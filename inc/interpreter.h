#ifndef BF_INTERPRETER_H
#define BF_INTERPRETER_H

#include <vector>
#include <stack>
#include <cstdint>

#include "lexer.h"

class Interpreter {
    public:
        Interpreter();
        ~Interpreter();
        bool run_statement(const std::string& statement);
        // tape manipulation
        void reset_head() {_pos = 0;}
        void print_tape();
        void clear_tape();
        void print_curr();
        // getters
        size_t pos() {return _pos;}
        std::string err_msg() {return _err_msg;}

    private:
        bool _exec_tok(Token tok);
        size_t _pos;    
        size_t _tok_pos;
        size_t _loopback;
        uint8_t* _tape;
        std::string _err_msg;
        std::vector<Token> _tokens;
        std::stack<size_t> _loopheads;
};

#endif