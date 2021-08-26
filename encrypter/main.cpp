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

int main()
{
    string filename("example.txt");
    string file_contents;

    file_contents = readFileIntoString(filename);
    cout << file_contents << endl;
    string key = "KEY";
 	cout << "message to send: " << file_contents << endl;
 	string encrypted_msg = encrypt(file_contents, key);
 	cout << "encrypted message: " << encrypted_msg << endl;
    writeStringToFile(filename, encrypted_msg);
    writeStringToFile("encrypted.txt", encrypted_msg);
    file_contents = readFileIntoString(filename);
 	string decrypted_msg = decrypt(file_contents, key);
 	cout << "decrypted message: " << decrypted_msg << endl;
    writeStringToFile("filename", decrypted_msg);
    return 0;
}
