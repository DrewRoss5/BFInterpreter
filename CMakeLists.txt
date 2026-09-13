cmake_minimum_required(VERSION 3.28)
project(BF_REPL VERSION 0.1.0)


# main executable
add_executable(brainfuck
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/interpreter.cpp"
    "${CMAKE_SOURCE_DIR}/src/lexer.cpp"
)
target_include_directories(brainfuck PRIVATE "${CMAKE_SOURCE_DIR}/inc")