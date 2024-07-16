#include "ast.hpp"
#include <stdio.h>
extern void yyerror(const char *s);
extern int yylex(void);
extern FILE* yyin;
extern int yyparse(void);
extern int yylineno;
extern char* yytext;

extern ast::ASTNode *root;
#define LAB2 2
#define LAB3 3
#define LAB4 4

#ifdef LAB2
#include "symboltable.hpp"
#endif
#ifdef LAB3
#include "irgenerator.hpp"
#endif
#ifdef LAB4
#include "assemblygenerator.hpp"
static const std::string ir_file = "./temp.ir";
#endif

int main(int argc, char** argv) {
    
    #ifndef LAB3
        if (argc != 2) {
            fprintf(stderr, "Usage: compiler <filename>\n");
            return 1;
        }
    #endif
    #ifdef LAB3
        if (argc != 3) {
            fprintf(stderr, "Usage: compiler <inputfile> <outputfile>\n");
            return 1;
        }
    #endif

    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    yyin = inputFile;
    yyparse();
    // root->print(std::cout, 0);
    fclose(inputFile);
    #ifdef LAB2
        symboltable::SymbolTable st;
        st.analyze(root);
        // root->print(std::cout, 0);
    #endif

    #ifdef LAB3
    #ifndef LAB4
        irgenerator::IRGenerator irg(argv[2]);
        irg.translate(root);
        irg.closeFile();
    #endif
    #endif

    #ifdef LAB4
        irgenerator::IRGenerator irg(ir_file);
        irg.translate(root);
        irg.closeFile();
        assemblygenerator::AssemblyGenerator ag(argv[2]);
        ag.preProcess(irg.instructions);
        ag.allocateRegisters();
        ag.generateAssembly();
    #endif

    return 0;
}
