# 🧠💥 BFInterpreter 🧠💥 
A [BrainF*ck](https://en.wikipedia.org/wiki/Brainfuck) interpreter and REPL environment

## Getting Started
To compile the interpreter:
- Ensure CMake is installed.
- Clone this repo
- From the repo's local directory, run the following commands:
```
mkdir build
cd build
cmake ..
cmake --build .
```
This will give you a compiled `brainfuck` executable in the `build` directory

## Usage:
The interpreter can be used in one of two ways, either by running code from a file, or by using an interactive environment to write an run code on the fly.

### File:
To run a file, simply build the executable as shown, then call it with the path to your BF file, for example:
`build/brainfuck tests/hello_world.bf`
This will run the file and exit upon completion. The `test` directory has two example you try this with.

### REPL:
To start the REPL environment, simply call the executable with no arguments. This will start an interactive session. Inside the REPL, you can either enter BF code to run it immediately, or run one or more of the following commands:
- `:q` exits the program
- `:C` clears the terminal
- `:c` clears the tape, and sets all cells to `0`
- `:r` resets the head, setting the pointer index to `0`
- `:h` prints the current head index (0-indexed)
- `:p` prints the entire tape up to and including the current pointer

You can also use multiple commands at once, for example, enter:`:cr` to both clear the tape, and reset the head. 
