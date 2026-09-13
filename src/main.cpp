#include <iostream>
#include <fstream>

#include "interpreter.h"

bool run_command(const std::string& command, Interpreter& interp) {
    for (char c : command) {
        switch (c) {
            case 'r': interp.reset_head(); break;
            case 'p': interp.print_tape(); break;
            case 'c': interp.clear_tape(); break;
            case 'C': system("clear"); break;
            case 'h': 
                std::cout << interp.pos() << std::endl;
                break;
            case 'q':
                return false;
            default:
                std::cout << "Error: Unrecognized command character: " << c << std::endl;
                break;
        }
    }
    return true;
}

void repl() {
    std::string expr;
    Interpreter interp;
    bool success;
    std::cout << "Welcome to the BrainFuck REPL. Enter :q to quit" << std::endl;
    while (true) {
        std::getline(std::cin, expr);
        // check if this a repl command
        if (expr[0] == ':') {
            bool cont = run_command(expr.substr(1), interp);
            if (!cont)
                return;
        }
        // run the given text as a brainfuck expression
        interp.run_statement(expr);
        std::cout << std::endl;
    }
}


int run_file(const std::string& filepath) {
    // ensure file opens
    std::ifstream src_file(filepath);
    if (!src_file.is_open()) {
        std::cerr << "Error: Cannot read the input file. Does it exist?" << std::endl;
        return 1;
    }
    // read the file to a string
    std::stringstream buf;
    buf << src_file.rdbuf();
    Interpreter interp;
    bool success = interp.run_statement(buf.str());
    if (!success) {
        std::cout << "\nError: " << interp.err_msg() << std::endl;
        return 1;
    }
    std::cout << std::endl;
    return 0;
}

int main(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Error: This program takes up to one argument" << std::endl;
        return 1;
    }
    if (argc == 2) {
        return run_file(argv[1]);
    }
    repl();
    return 0;

}