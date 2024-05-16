#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include "encrypt.h"

using namespace std;

const size_t BLOCK_SIZE = 16;
vector<unsigned char> stringToBytes(string str);
void toMatrix(vector<unsigned char> bytes);

int main()
{
    FILE* original;
    const int bufferSize = 16;      //includes null
    char buffer[bufferSize] = {0};  //fill with 0's
    int i = 0;                      //generic counter
    char c;                         //temp character

    original = fopen("original.txt","r");
    if(original == NULL){
        cout << "File not found" << endl;
        return 1;
    }

    while(i<bufferSize){            //read file to buffer until 16 bytes or end of file, whichever comes first
        c = getc(original);
        if (c != EOF){
            buffer[i] = c;
            i++;
        }
        else break;
    }

    fclose(original);

    cout << buffer << endl;         //print original file as a string, actual memory contains 16 bytes padded with 0's
    cout << "characters read from file = " << i << endl;

    string originalAsCharString = buffer;   //original text as a string


    stringstream ss;
    for(i=0; i<bufferSize; ++i)
        ss << hex << (int)buffer[i];
    string originalAsHexString = ss.str();  //save original text as a hex string variable
    cout << originalAsHexString << endl;    //print original text as hex
    

// Save decrypted string to a file 
    cout << buffer << endl;     //prints buffer which contains decrypted file
    
    // creates a file called decrypted and writes the buffer to it as a text string
    FILE* decrypted;
    decrypted = fopen("decrypted.txt","w");
    if(decrypted == NULL){
        cout << "File was not created" << endl;
        return 1;
    }

    for( i=0 ; i<(bufferSize-1) ; i++) {
        putc(buffer[i], decrypted);
    }
    putc(0, decrypted); //terminates with a 0
    fclose(decrypted);
    
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
