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
void parse_bf(const std::string& src, std::vector<Token>& out) {
    std::stringstream stream(src);
    char curr; 
    Token next;
    while (stream.get(curr)) {
        switch (curr)
        {
            case '+': next = INC; break;
            case '-': next = DEC; break;
            case '<': next = SHIFT_LEFT; break;
            case '>': next = SHIFT_RIGHT; break;
            case '[': next = OPEN_LOOP; break;
            case ']': next = CLOSE_LOOP; break;
            case '.': next = PRINT; break;
            case ',': next = READ; break;
            default: next = COMMENT; break;
        }
    }
    if (next != COMMENT)
        out.push_back(next);
}

#endif