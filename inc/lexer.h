#ifndef BF_LEXER_H
#define BF_LEXER_H

#include <string>
#include <sstream>
#include <vector>

enum Token {
    INC,
    DEC,
    SHIFT_LEFT,
    SHIFT_RIGHT,
    OPEN_LOOP,
    CLOSE_LOOP,
    PRINT,
    READ,
    COMMENT
};

// parses the expression into tokens. This is only to strip comments
void parse_bf(const std::string& src, std::vector<Token>& out);

#endif