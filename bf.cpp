#include <fstream>
#include <iostream>
#include <stack>
#include <sstream>

#define BUFFER_SIZE 30000
#define ERROR_STATUS 1

using namespace std;

/* Globals */
static char *ptr = (char*)calloc(BUFFER_SIZE, sizeof(char));
static stack<int> loopIndices;

void exitWithErrorMessage(std::string message) {
    cerr << message << endl;
    exit(ERROR_STATUS);
}

string readContents(char *argv[]) {
    ifstream inFile(argv[1], ios::in);
    char ch;
    stringstream contentStream;
    while (inFile.get(ch)) {
        contentStream << ch;
    }
    return contentStream.str();
}

void processSymbol(char symbol, int& index, string contents) {
    switch(symbol) {
        case '>': {
            ptr++;
            break;
        } case '<': {
            ptr--;
            break;
        } case '+': {
            (*ptr)++;
            break;
        } case '-': {
            (*ptr)--;
            break;
        } case '[': {
            // Most of the code I've seen treats '[' as a do-while loop
            loopIndices.push(index);
            break;
        } case ']': {
            if (*ptr) {
                index = loopIndices.top();
            } else {
                loopIndices.pop();
            }
            break;
        } case ',': {
            cin >> *ptr;
            break;
        } case '.': {
            cout << *ptr;
            break;
        } case '#': {
            // TODO: Add debug symbol support
            break;
        } default:
            break;
    }
}

void run(string contents) {
    for (int i = 0; i < contents.length(); i++) {
        processSymbol(contents[i], i, contents);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        exitWithErrorMessage("Please provide a file to interpret.");
    } else {
        string contents = readContents(argv);
        // TODO: Add preprocessing for loop closure and debug symbols
        run(contents);
        return 0;
    }
}