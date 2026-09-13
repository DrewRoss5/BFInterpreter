#include <iostream>
#include <limits>

#include "interpreter.h"

#define TAPE_SIZE 30000
#define MAX_POS 29999

Interpreter::Interpreter() {
    // initialize tape
    _tape = new uint8_t[TAPE_SIZE];
    for (int i = 0; i < TAPE_SIZE; i++)
        _tape[i] = 0;
    // initialize other members
    _pos = 0;
    _loopback = 0;
}

Interpreter::~Interpreter() {
    delete[] _tape;
}

bool Interpreter::run_statement(const std::string& statement) {
    bool success;
    // tokenize the expression
    _tokens.clear();
    parse_bf(statement, _tokens);
    // run each token
    _tok_pos = 0;
    while (_tok_pos < _tokens.size()) {
        success = _exec_tok(_tokens[_tok_pos]);
        if (!success)
            return false;
        _tok_pos++;
    }
    // ensure that all loops were closed
    if (!_loopheads.empty()) {
        _err_msg = "Unclosed loop found";
        return false;
    }
    return true;
}

bool Interpreter::_exec_tok(Token tok) {
    char tmp;
    switch (tok) {
        case INC: _tape[_pos]++; break;
        case DEC: _tape[_pos]--; break;
        case SHIFT_LEFT:
            if (_pos == 0) {
                _err_msg = "Tape head out of bounds (cannot go below 0)";
                return false;
            }
            _pos--; 
            break;
        case SHIFT_RIGHT:
            if (_pos == MAX_POS) {
                _err_msg = "Tape head out of bounds (cannot go above 29,999)";
                return false;
            }
            _pos++;
            break;
        case PRINT: 
            std::cout << static_cast<char>(_tape[_pos]) << std::flush;
            break;
        case READ:
            std::cin >> tmp;
            _tape[_pos] = tmp;
            break;
        case OPEN_LOOP:
            // update our loopback address, and cache the current
            _loopheads.push(_loopback);
            _loopback = _tok_pos;
            break;
        case CLOSE_LOOP:
            // repeat the loop if this is non-zero
            if (_tape[_pos])
                _tok_pos = _loopback;
            // exit the loop
            else {
                // ensure that we're actually in a loop
                if (_loopheads.empty()) {
                    _err_msg = "Loop exit found outside of loop";
                    return false;
                }
                _loopback = _loopheads.top();
                _loopheads.pop();
            }
            break;
    }
    return true;
}

// REPL functions
void Interpreter::clear_tape() {
    for (int i = 0; i < TAPE_SIZE; i++)
        _tape[i] = 0;
}

void Interpreter::print_curr() {
    std::cout << _tape[_pos] << std::endl;
}

// prints all cells from 0 up to and including the current cell
void Interpreter::print_tape() {
    for (int i = 0; i <= _pos; i++) {
        std::cout << " " << _tape[_pos] << " ";
    }
    std::cout << std::endl;
}