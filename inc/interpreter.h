#ifndef BF_INTERPRETER_H
#define BF_INTERPRETER_H

#include <vector>
#include <stack>

#include "lexer.h"

class Interpreter {
    public:
        Interpreter();
        void run_statement(std::string& statement);
        void reset_head();
        void print_tape();
        void clear_tape();
        void print_cell(size_t pos);
        size_t pos() {return _pos;}
    private:
        size_t _pos;    
        unsigned char* _tape;
        std::vector<Token> _tokens;
        std::stack<size_t> _loopheads;
};

#endif