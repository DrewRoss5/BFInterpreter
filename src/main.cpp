#include <iostream>

#include "interpreter.h"

void run_file(const std::string& filepath) {
    std::cout << "Whoops! Running files is not yet implemented" << std::endl;
}

void repl() {
    std::cout << "Whoops! REPL environment is not yet implemented" << std::endl;
}

int main(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Error: This program takes up to one argument" << std::endl;
        return 1;
    }
    if (argc == 2) {
        run_file(argv[1]);
        return 0;
    }
    repl();
    return 0;

}