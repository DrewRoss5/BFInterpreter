#include <iostream>
#include <fstream>

#include "interpreter.h"

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

void repl() {
    std::cout << "Whoops! REPL environment is not yet implemented" << std::endl;
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