#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include "irgenerator.hpp"
#include "graph.hpp"

namespace assemblygenerator
{
    struct liveInfo {
        int id = 0;
        std::set<std::string> liveIn;
        std::set<std::string> liveOut;
        std::set<std::string> def;
        std::set<std::string> use;
        std::unordered_set<liveInfo*> succ;
    };
    class RegisterAllocator {
    public:
        RegisterAllocator();
        void splitModules();
        void generateFlow(std::list<irgenerator::instructionNode>& instructions);
        void liveAnalysis();
        void buildInterferenceGraph();
        void colorGraph();
        void eliminateSpills(std::list<irgenerator::instructionNode> &instructions);
        void allocateRegisters();
        void reset();
        std::list<irgenerator::instructionNode> instructions;
        std::vector<std::list<irgenerator::instructionNode>> modules;
        std::unordered_map<std::string, int> funcParamCount;
        static const std::vector<std::string> colors;
    private:
        std::unordered_map<std::string, liveInfo*> liveInfoMap;
        std::vector<liveInfo*> liveInfoTable;
        graph::Graph interferenceGraph;
    };

    class AssemblyGenerator {
    public:
        AssemblyGenerator();
        AssemblyGenerator(std::string assemblyOutputFile);
        void preProcess(std::list<irgenerator::instructionNode> instructions);
        void allocateRegisters();
        void generateAssembly();
        RegisterAllocator regAlloc;
        static const std::string libc_start_main[2];
    private:
        std::ofstream assemblyOutputFile;
        std::list<irgenerator::instructionNode> instructionsData;
        std::list<irgenerator::instructionNode> instructionsText;
    };
}
