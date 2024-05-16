#include <iostream>
#include <vector>

#include "encrypt.h"

using namespace std;

const size_t BLOCK_SIZE = 16;
vector<unsigned char> stringToBytes(string str);
void toMatrix(vector<unsigned char> bytes);

int main(){
    //read file (16 char at a time)
    //input string to 16 char
    //add padding if needed
    return 0;
}

//convert string to vector of char (16 bytes)
vector<unsigned char> stringToBytes(string str){
    vector<unsigned char> string_bytes(str.begin(), str.end());
    size_t padding_length = BLOCK_SIZE - (string_bytes.size() % BLOCK_SIZE);
    //add bytes (padding) for string that is shorter than 16 bytes
    for (size_t i = 0; i < padding_length; i++)
    {
        string_bytes.push_back(padding_length);
    }
    return string_bytes;
}

void toMatrix(unsigned char matrix[4][4], vector<unsigned char>& bytes) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = bytes[4*i+j];
        }
    }
}