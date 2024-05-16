#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

#include "aes.h"

using namespace std;

vector<unsigned char> stringToBytes(string str);
void toMatrix(vector<unsigned char> bytes);
void encryptFile(const string& fileName);
void decryptFile(const string& fileName);

int main(){
    cout << "AES File Encryption/Decryption" << endl;
    cout << "1. Encrypt a text file" << endl;
    cout << "2. Decrypt a text file" << endl;
    cout << "3. Exit" << endl;

    string fileName = "";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Input text file:" << endl;
        cin >> fileName;
        
        encryptFile(fileName);
    }
    else if (choice == 2){
        cout << "Input text file:" << endl;
        cin >> fileName;

        decryptFile(fileName);
    }
    else if (choice == 3)
    {
        return 0;
    }
    else{
        cout << "Input Error.";
        return 1;
    }
    return 0;
}

void encryptFile(const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Cannot open file" << endl;
    }

    string line;
    string toEncrypt;
    string result = "";
    unsigned char matrix[4][4];

    while(getline(inputFile, line)) {
        int start = 0;

        while (start < line.length()) {
            if (start + 16 < line.length() - 16) {
                toEncrypt = line.substr(start, 16);
                start += 16;
            } else {
                toEncrypt = line.substr(start, line.length()-start);
                start = line.length();
            }

            toMatrix(toEncrypt, matrix);
            result += decryptedMessage(matrix);
        }
    }
}

void decryptFile(const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Cannot open file" << endl;
    }

    string line;
    string toDecrypt;
    string result = "";
    unsigned char matrix[4][4];

    while(getline(inputFile, line)) {
        int start = 0;

        while (start < line.length()) {
            if (start + 16 < line.length() - 16) {
                toDecrypt = line.substr(start, 16);
                start += 16;
            } else {
                toDecrypt = line.substr(start, line.length()-start);
                start = line.length();
            }

            toMatrix(toDecrypt, matrix);
            result += decryptedMessage(matrix);
        }
        cout << result << endl;
        result = "";
    }
}

void toMatrix(const string& str, unsigned char matrix[4][4]) {
    unsigned char bytes[16];
    for (int i = 0; i < str.length(); i++) {
        bytes[0] = static_cast<unsigned char>(str.at(i));
    }

    size_t padding_length = 16 - (str.length() % 16);
    //add bytes (padding) for string that is shorter than 16 bytes
    for (size_t i = 0; i < padding_length; i++)
    {
        bytes[str.length() + i] = (padding_length);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = bytes[4*i+j];
        }
    }
}
