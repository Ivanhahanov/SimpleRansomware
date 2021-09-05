#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "encrypt.h"
#include <fstream>

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;

string readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

void writeStringToFile(const string& path, const string& text){
    ofstream output_file(path);
    output_file << text;
    output_file.close();
}

int main(int argc, char** argv) {
    string filename = argv[1];
    string key = argv[2];
    string file_contents;
   
    file_contents = readFileIntoString(filename);
    writeStringToFile(filename, encrypt(file_contents, key));

    return 0;
}

