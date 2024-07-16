bison --yacc -dv sysy.y
flex sysy.l
g++ -g -o compiler main.cc assemblygenerator.cpp graph.cpp irgenerator.cpp symboltable.cpp y.tab.c lex.yy.c ast.cpp
