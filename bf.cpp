#include <fstream>
#include <iostream>
#include <sstream>

#define BUFFER_SIZE 30000
#define ERROR_STATUS 1

using namespace std;

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

void processSymbol(char symbol, char*& ptr) {
    switch(symbol) {
        case '>':
            ptr++;
            break;
        case '<':
            ptr--;
            break;
        case '+':
            (*ptr)++;
            break;
        case '-':
            (*ptr)--;
            break;
        case '[':
            exitWithErrorMessage("Symbol '[' is currently not supported.");
            break;
        case ']':
            exitWithErrorMessage("Symbol ']' is currently not supported.");
            break;
        case ',':
            cin >> *ptr;
            break;
        case '.':
            cout << *ptr;
            break;
        case '#':
        default:
            break;
    }
}

void run(string contents) {
    char *ptr = (char*)malloc(BUFFER_SIZE * sizeof(char));
    for (char ch : contents) {
        processSymbol(ch, ptr);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        exitWithErrorMessage("Please provide a file to interpret.");
    } else {
        string contents = readContents(argv);
        run(contents);
        return 0;
    }
}