#include <iostream>

#include <Chunk.h>
#include <Debug.h>
#include "VirtualMachine.h"
#include <Lexer.h>
#include <Parser.h>
#include <CodeGen.h>
#include <BinaryExpr.h>
#include <NotSoPrettyPrinter.h>

int main() {

    std::cout << "Lexer:" << std::endl;
    Lexer lexer("1+2+3");
    auto tokens = lexer.lex();
    for (auto t : *tokens) {
        std::cout << " " << t.toString();
    }
    std::cout << std::endl;

    Parser parser(tokens);
    auto ast = parser.parse();

    NotSoPrettyPrinter printer;
    std::cout << "AST:" << printer.print(ast) << std::endl;

    CodeGen codeGen;
    auto chunk = codeGen.generate(ast);

    dissassembleChunk(chunk,"test chunk");

    VirtualMachine vm;
    vm.interpret(chunk);

    return 0;
}

