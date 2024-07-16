#include "assemblygenerator.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <algorithm>

#define DEBUG_PRE 0
#define DEBUG_LIVE 1
#define DEBUG_GRAPH 2
#define DEBUG_COLOR 3

namespace assemblygenerator {
    // for debug
    #ifdef DEBUG_PRE
    static std::ofstream preFile("pre.txt");
    #endif
    #ifdef DEBUG_LIVE
    static std::ofstream liveFile("live.txt");
    #endif
    #ifdef DEBUG_GRAPH
    static std::ofstream graphFile("graph.txt");
    #endif
    #ifdef DEBUG_COLOR
    static std::ofstream colorFile("color.txt");
    #endif

    bool isNameVariable(std::string name) {
        return name.size() > 1 && name[0] == '_' && name[1] == '_';
    }


    const std::vector<std::string> RegisterAllocator::colors = {"t0", "t1", "t2", "s1", 
    "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6", 
    "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7"};

    const std::string AssemblyGenerator::libc_start_main[2] = {
        ".text\n",
        ".data\n"
    };

    AssemblyGenerator::AssemblyGenerator() = default;

    AssemblyGenerator::AssemblyGenerator(std::string assemblyOutputFileName) {
        assemblyOutputFile = std::ofstream(assemblyOutputFileName);
    }

    void AssemblyGenerator::preProcess(std::list<irgenerator::instructionNode> instructions) {
        instructions.push_back( {"ENDFUNCTION", "", "", ""} );
        int argCount = 0;
        bool inFunction = false;
        for (auto it = instructions.begin(); it != instructions.end(); it++){
            irgenerator::instructionNode& instruction = *it;
            if (instruction.opcode == "arg") {
                if (argCount < 8) {
                    instruction.opcode = "mv";
                    instruction.arg2 = instruction.arg1;
                    instruction.arg1 = "a" + std::to_string(argCount);
                    argCount++;
                } else {
                    instructions.insert(it, {"addi", "sp", "sp", "-4"});
                    instruction.opcode = "sw";
                    instruction.arg2 = "sp";
                    instruction.arg3 = "0";
                }
            } else if (instruction.opcode == "call") {
                argCount = 0;
                std::string funcName = instruction.arg2;
                std::string fetchValue = instruction.arg1;
                if (instruction.arg1 != "") {
                    instruction.opcode = "mv";
                    instruction.arg1 = fetchValue;
                    instruction.arg2 = "a0";
                    instructions.insert(it, {"call", funcName, "", ""});
                } else {
                    instruction.opcode = "call";
                    instruction.arg1 = funcName;
                    instruction.arg2 = "";
                }
            } else if (instruction.opcode == "FUNCTION") {
                instructions.insert(it, {"ENDFUNCTION", "", "", ""});
                int paramCount = 0;
                std::string funcName = instruction.arg1;
                ++it;
                for (auto itp = it; itp != instructions.end(); ++itp) {
                    irgenerator::instructionNode& param = *itp;
                    if (param.opcode == "PARAM") {
                        if (paramCount < 8) {
                            param.opcode = "mv";
                            param.arg2 = "a" + std::to_string(paramCount);
                            paramCount++;
                        } else {
                            paramCount++;
                        }
                    } else {
                        it = itp;
                        if (paramCount >= 9) {
                            --itp;
                            int tmpParamCount = paramCount;
                            for (itp; (*itp).opcode == "PARAM"; --itp) {
                                irgenerator::instructionNode& param = *itp;
                                tmpParamCount--;
                                param.opcode = "lw";
                                param.arg2 = "sp";
                                param.arg3 = std::to_string((paramCount - tmpParamCount - 1) * 4);
                            }
                        }
                        break;
                    }
                }
                if (paramCount >= 9) {
                    instructions.insert(it, {"addi", "sp", "sp", std::to_string((paramCount - 8) * 4)});
                }
                regAlloc.funcParamCount[funcName] = paramCount;
                instructions.insert(it, {"addi", "sp", "sp", "-8"});
                instructions.insert(it, {"sw", "ra", "sp", "4"});
                instructions.insert(it, {"sw", "fp", "sp", "0"});
                instructions.insert(it, {"mv", "fp", "sp", ""});
                --it;
            } else if (instruction.opcode == "return") {
                std::string returnValue = instruction.arg1;
                instructions.insert(it, {"mv", "sp", "fp", ""});
                instructions.insert(it, {"lw", "fp", "sp", "0"});
                instructions.insert(it, {"lw", "ra", "sp", "4"});
                instructions.insert(it, {"addi", "sp", "sp", "8"});
                if (returnValue != "") {
                    instruction.opcode = "ret";
                    instructions.insert(it, {"mv", "a0", returnValue, ""});
                } else {
                    instruction.opcode = "ret";
                }
                instruction.arg1 = "";
            } else if (instruction.opcode == "DEC") {
                std::string refName = instruction.arg1;
                int size = std::stoi(instruction.arg2);
                instructions.insert(it, {"addi", "sp", "sp", std::to_string(-size)});
                instruction.opcode = "mv";
                instruction.arg1 = refName;
                instruction.arg2 = "sp";
            } else if (instruction.opcode == "muli") {
                if (instruction.arg3 == "1") {
                    if (instruction.arg1 == instruction.arg2) {
                        it = instructions.erase(it);
                        --it;
                    } else {
                        instruction.opcode = "mv";
                        instruction.arg3 = "";
                    }
                } else if (instruction.arg3 == "2") {
                    instruction.opcode = "add";
                    instruction.arg3 = instruction.arg2;
                } else {
                    std::string sym = instruction.arg2 + "_ct";
                    instructions.insert(it, {"li", sym, instruction.arg3, ""});
                    instruction.opcode = "mul";
                    instruction.arg3 = sym;
                }
            } else if (instruction.opcode == "addi") {
                if (instruction.arg3 == "0") {
                    if (instruction.arg1 == instruction.arg2) {
                        it = instructions.erase(it);
                        --it;
                    } else {
                        instruction.opcode = "mv";
                        instruction.arg3 = "";
                    }
                }
            }
        }
        for (auto it = instructions.begin(); it != instructions.end(); it++) {
            regAlloc.instructions.push_back(*it);
        }
        #ifdef DEBUG_PRE
        for (auto instruction : regAlloc.instructions) {
            preFile << instruction.opcode << " " << instruction.arg1 << " " << instruction.arg2 << " " << instruction.arg3 << std::endl;
        }
        preFile << "END" << std::endl;
        #endif
    }

    void AssemblyGenerator::allocateRegisters() {
        regAlloc.allocateRegisters();
        for (auto instruction : regAlloc.instructions) {
            if (instruction.opcode == "GLOBAL" || instruction.opcode == "WORD") {
                instructionsData.push_back(instruction);
            }
        }
        for (auto it = regAlloc.modules.rbegin(); it != regAlloc.modules.rend(); it++) {
            std::list<irgenerator::instructionNode> module = *it;
            std::string funcName = module.front().arg1;
            for (auto instruction : module) {
                if (instruction.opcode == "ret" && funcName == "main ") {
                    instructionsText.push_back({"li", "a0", "10", ""});
                    instructionsText.push_back({"ecall", "", "", ""});
                } else if (instruction.opcode == "call" && instruction.arg1 == "read ") {
                    instructionsText.push_back({"li", "a0", "6", ""});
                    instructionsText.push_back({"ecall", "", "", ""});
                } else if (instruction.opcode == "call" && instruction.arg1 == "write ") {
                    instructionsText.push_back({"mv", "a1", "a0", ""});
                    instructionsText.push_back({"li", "a0", "1", ""});
                    instructionsText.push_back({"ecall", "", "", ""});
                } else {
                    instructionsText.push_back(instruction);
                }
            }
        }
    }

    void AssemblyGenerator::generateAssembly() {
        assemblyOutputFile << libc_start_main[0] << std::endl;
        for (auto instruction : instructionsText) {
            if (instruction.opcode == "FUNCTION" || instruction.opcode == "LABEL") {
                assemblyOutputFile << instruction.arg1 << ":" << std::endl;
            } else if (instruction.opcode == "ret") {
                assemblyOutputFile << "ret" << std::endl;
            } else if (instruction.opcode == "j" || instruction.opcode == "call") {
                assemblyOutputFile << instruction.opcode << " " << instruction.arg1 << std::endl;
            } else if (instruction.opcode == "mv" || instruction.opcode == "la" || instruction.opcode == "li") {
                assemblyOutputFile << instruction.opcode << " " << instruction.arg1 << ", " << instruction.arg2 << std::endl;
            } else if (instruction.opcode[0] == 'b' 
            || instruction.opcode == "add" || instruction.opcode == "sub" || instruction.opcode == "mul" || instruction.opcode == "div" || instruction.opcode == "rem" 
            || instruction.opcode == "addi" || instruction.opcode == "muli") {
                assemblyOutputFile << instruction.opcode << " " << instruction.arg1 << ", " << instruction.arg2 << ", " << instruction.arg3 << std::endl;
            } else if (instruction.opcode == "lw" || instruction.opcode == "sw") {
                assemblyOutputFile << instruction.opcode << " " << instruction.arg1 << ", " << instruction.arg3 << "(" << instruction.arg2 << ")" << std::endl;
            } else {
                assemblyOutputFile << instruction.opcode << std::endl;
            }
        }
        assemblyOutputFile << libc_start_main[1] << std::endl;
        for (auto instruction : instructionsData) {
            if (instruction.opcode == "GLOBAL") {
                assemblyOutputFile << instruction.arg1 << ": " << std::endl;
            } else if (instruction.opcode == "WORD") {
                assemblyOutputFile << ".word " << instruction.arg1 << std::endl;
            }
        }
    }

    RegisterAllocator::RegisterAllocator() {
        interferenceGraph = graph::Graph(26);
    }

    void RegisterAllocator::splitModules() {
        std::list<irgenerator::instructionNode> module;
        for (irgenerator::instructionNode instruction : instructions) {
            if (instruction.opcode == "GLOBAL" || instruction.opcode == "WORD") {
                continue;
            }
            if (instruction.opcode == "ENDFUNCTION") {
                if (!module.empty()) {
                    modules.push_back(module);
                    module.clear();
                }
            } else {
                module.push_back(instruction);
            }
        }
    }

    bool isNameSpecificReg(std::string name) {
        return name == "fp" || name == "sp" || name == "zero" || name == "ra";
    }

    void RegisterAllocator::generateFlow(std::list<irgenerator::instructionNode>& instructions) {
        std::string label = "";
        int idIndex = 0;
        for (irgenerator::instructionNode instruction : instructions) {
            if (instruction.opcode == "LABEL") {
                label = instruction.arg1;
            }
            liveInfoTable.push_back(new liveInfo());
            liveInfoTable.back()->id = idIndex++;
            if (label != "") {
                liveInfoMap[label] = liveInfoTable.back();
                label = "";
            }
        }
        int liveIndex = 0;
        liveInfo* pre = nullptr;
        for (auto instruction : instructions) {
            liveInfo* info = liveInfoTable[liveIndex++];
            
            if (instruction.opcode == "LABEL") {
                // do nothing
            } else if (instruction.opcode == "j") {
                info->succ.insert(liveInfoMap[instruction.arg1]);
            } else if (instruction.opcode[0] == 'b') {
                if(!isNameSpecificReg(instruction.arg1)) info->use.insert(instruction.arg1);
                if(!isNameSpecificReg(instruction.arg2)) info->use.insert(instruction.arg2);
                info->succ.insert(liveInfoMap[instruction.arg3]);
            } else if (instruction.opcode == "la" || instruction.opcode == "li") {
                info->def.insert(instruction.arg1);
            } else if (instruction.opcode == "addi" || instruction.opcode == "muli" || instruction.opcode == "mv" || instruction.opcode == "lw") {
                if(!isNameSpecificReg(instruction.arg1)) info->def.insert(instruction.arg1);
                if(!isNameSpecificReg(instruction.arg2)) info->use.insert(instruction.arg2);
            } else if (instruction.opcode == "sw") {
                if(!isNameSpecificReg(instruction.arg1)) info->use.insert(instruction.arg1);
                if(!isNameSpecificReg(instruction.arg2)) info->use.insert(instruction.arg2);
            } else if (instruction.opcode == "add" || instruction.opcode == "sub" || instruction.opcode == "mul" || instruction.opcode == "div" || instruction.opcode == "rem") {
                if(!isNameSpecificReg(instruction.arg1)) info->def.insert(instruction.arg1);
                if(!isNameSpecificReg(instruction.arg2)) info->use.insert(instruction.arg2);
                if(!isNameSpecificReg(instruction.arg3)) info->use.insert(instruction.arg3);
            } else if (instruction.opcode == "call") {
                int paramCount = funcParamCount[instruction.arg1];
                paramCount = std::min(paramCount, 8);
                for (int i = 0; i < paramCount; i++) {
                    info->use.insert("a" + std::to_string(i));
                }
                info->def.insert("a0");
            }
            if (pre != nullptr) {
                pre->succ.insert(info);
            }
            pre = (instruction.opcode == "j") ? nullptr : info;
        }
    }

    void RegisterAllocator::liveAnalysis() {
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = liveInfoTable.size() - 1; i >= 0; i--) {
                liveInfo* info = liveInfoTable[i];
                std::set<std::string> newLiveOut;
                for (liveInfo* succ : info->succ) {
                    std::set_union(newLiveOut.begin(), newLiveOut.end(), 
                    succ->liveIn.begin(), succ->liveIn.end(), std::inserter(newLiveOut, newLiveOut.begin()));
                }
                if (newLiveOut != info->liveOut) {
                    changed = true;
                    info->liveOut = newLiveOut;
                }
                std::set<std::string> newLiveIn;
                std::set_difference(newLiveOut.begin(), newLiveOut.end(),
                info->def.begin(), info->def.end(), std::inserter(newLiveIn, newLiveIn.begin()));
                std::set_union(newLiveIn.begin(), newLiveIn.end(),
                info->use.begin(), info->use.end(), std::inserter(newLiveIn, newLiveIn.begin()));
                if (newLiveIn != info->liveIn) {
                    changed = true;
                    info->liveIn = newLiveIn;
                }
            }
        }
        #ifdef DEBUG_LIVE
        for (liveInfo* info : liveInfoTable) {
            liveFile << "instruction:" << info->id << std::endl;
            liveFile << "def: ";
            for (std::string def : info->def) {
                liveFile << def << " ";
            }
            liveFile << std::endl;
            liveFile << "use: ";
            for (std::string use : info->use) {
                liveFile << use << " ";
            }
            liveFile << std::endl;
            liveFile << "liveIn: ";
            for (std::string liveIn : info->liveIn) {
                liveFile << liveIn << " ";
            }
            liveFile << std::endl;
            liveFile << "liveOut: ";
            for (std::string liveOut : info->liveOut) {
                liveFile << liveOut << " ";
            }
            liveFile << std::endl;
            liveFile << "succ: ";
            for (liveInfo* succ : info->succ) {
                liveFile << succ->id << " ";
            }
            liveFile << std::endl;
        }
        liveFile << "END" << std::endl;
        #endif
    }

    void RegisterAllocator::buildInterferenceGraph() {
        for (liveInfo* info : liveInfoTable) {
            if (info->liveIn.size() == 1) {
                interferenceGraph.createNode(*info->liveIn.begin());
            }
            for (std::string reg1 : info->liveIn) {
                for (std::string reg2 : info->liveIn) {
                    if (reg1 == reg2) {
                        continue;
                    }
                    interferenceGraph.addEdge(reg1, reg2);
                }
            }
        }
        #ifdef DEBUG_GRAPH
        for (auto node : interferenceGraph.nodes) {
            graphFile << node.first << ": ";
            for (auto adj : node.second->adj) {
                graphFile << adj->name << " ";
            }
            graphFile << std::endl;
        }
        graphFile << "END" << std::endl;
        #endif
    }

    void RegisterAllocator::colorGraph() {
        interferenceGraph.colorGraph();
        #ifdef DEBUG_COLOR
        for (auto node : interferenceGraph.nodes) {
            colorFile << node.first << " " << node.second->color << std::endl;
        }
        colorFile << "END" << std::endl;
        #endif
    }

    void RegisterAllocator::eliminateSpills(std::list<irgenerator::instructionNode>& instructions) {
        int liveIndex = 0;
        int stackDepth = 0;
        std::unordered_map<std::string, int> stackPos;
        for (auto spill : interferenceGraph.spills) {
            stackDepth += 4;
            stackPos[spill] = stackDepth;
        }
        for (auto it = instructions.begin(); it != instructions.end(); it++) {
            irgenerator::instructionNode& instruction = *it;
            liveInfo* info = liveInfoTable[liveIndex++];
            if (instruction.arg1 == "fp") {
                ++it;
                it = instructions.insert(it, {"addi", "sp", "sp", std::to_string(-stackDepth)});
            }
            for (auto defined : info->def) {
                if (interferenceGraph.spills.find(defined) != interferenceGraph.spills.end()) {
                    std::string spill = defined + "_spill1";
                    int pos = stackPos[defined];
                    instruction.arg1 = spill;
                    ++it;
                    it = instructions.insert(it, {"sw", spill, "fp", std::to_string(-pos)});
                }
            }
            for (auto used : info->use) {
                if (interferenceGraph.spills.find(used) != interferenceGraph.spills.end()) {
                    std::string spill = used + "_spill2";
                    int pos = stackPos[used];
                    if (instruction.arg1 == used) {
                        if (instruction.opcode == "sw" || instruction.opcode[0] == 'b') {
                            instruction.arg1 = spill;
                            instructions.insert(it, {"lw", spill, "fp", std::to_string(-pos)});
                        }
                    }
                    if (instruction.arg2 == used) {
                        instruction.arg2 = spill;
                        instructions.insert(it, {"lw", spill, "fp", std::to_string(-pos)});
                    }
                    if (instruction.arg3 == used) {
                        instruction.arg3 = spill;
                        instructions.insert(it, {"lw", spill, "fp", std::to_string(-pos)});
                    }
                }
            } 
        }
    }

    void RegisterAllocator::allocateRegisters() {
        splitModules();
        for (std::list<irgenerator::instructionNode>& module : modules) {
            while (true) {
                reset();
                generateFlow(module);
                liveAnalysis();
                buildInterferenceGraph();
                colorGraph();
                bool success = interferenceGraph.spills.empty();
                if (success) {
                    // insert code for caller-save
                    int liveIndex = 0;
                    for (auto it = module.begin(); it != module.end(); it++) {
                        irgenerator::instructionNode& instruction = *it;
                        liveInfo* info = liveInfoTable[liveIndex++];
                        if (instruction.opcode == "call") {
                            if (!info->use.empty()) {
                                while ((*it).arg1 != "a0") {
                                    --it;
                                    --liveIndex;
                                }
                            }
                            info = liveInfoTable[liveIndex - 1];

                            int liveCount = info->liveIn.size();
                            if (liveCount) module.insert(it, {"addi", "sp", "sp", std::to_string(-liveCount * 4)});
                            liveCount = 0;
                            for (auto lived : info->liveIn) {
                                module.insert(it, {"sw", lived, "sp", std::to_string(liveCount * 4)});
                                liveCount++;
                            }
                            while ((*it).opcode != "call") {
                                ++it;
                                ++liveIndex;
                            }
                            ++it;
                            ++liveIndex;
                            liveCount = 0;
                            for (auto lived : info->liveIn) {
                                module.insert(it, {"lw", lived, "sp", std::to_string(liveCount * 4)});
                                liveCount++;
                            }
                            if (liveCount) module.insert(it, {"addi", "sp", "sp", std::to_string(liveCount * 4)});
                        }
                    }
                    for (auto it = module.begin(); it != module.end(); it++) {
                        irgenerator::instructionNode& instruction = *it;
                        if (isupper(instruction.opcode[0])) {
                            continue;
                        }
                        bool isUnUsed = false;
                        if (instruction.arg1 != "" && isNameVariable(instruction.arg1)) {
                            if (interferenceGraph.nodes.find(instruction.arg1) != interferenceGraph.nodes.end()) {
                                instruction.arg1 = colors[interferenceGraph.nodes[instruction.arg1]->color];
                            } else {
                                isUnUsed = true;
                            }
                        }
                        if (instruction.arg2 != "" && isNameVariable(instruction.arg2)) {
                            if (interferenceGraph.nodes.find(instruction.arg2) != interferenceGraph.nodes.end()) {
                                instruction.arg2 = colors[interferenceGraph.nodes[instruction.arg2]->color];
                            }
                        }
                        if (instruction.arg3 != "" && isNameVariable(instruction.arg3)) {
                            if (interferenceGraph.nodes.find(instruction.arg3) != interferenceGraph.nodes.end()) {
                                instruction.arg3 = colors[interferenceGraph.nodes[instruction.arg3]->color];
                            }
                        }
                        if (instruction.opcode == "mv" && instruction.arg1 == instruction.arg2) {
                            isUnUsed = true;
                        }
                        // isUnUsed = false;
                        if (isUnUsed) {
                            it = module.erase(it);
                            --it;
                        }
                    }
                    break;
                }
                eliminateSpills(module);
            }
        }
    }

    void RegisterAllocator::reset() {
        liveInfoMap.clear();
        for (liveInfo* info : liveInfoTable) {
            delete info;
        }
        liveInfoTable.clear();
        interferenceGraph.clearGraph();
    }    

}