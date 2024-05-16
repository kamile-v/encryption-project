#ifndef AES_H
#define AES_H

#include <string>
using namespace std;

const int MATRIX_SIZE = 4;

//reference tables
extern unsigned char sBox[256];
extern unsigned char inverseSBox[256];
extern unsigned char rCon[10];
extern unsigned char shiftIndivMatrix[MATRIX_SIZE][MATRIX_SIZE];
extern unsigned char inverseShiftIndivMatrix[MATRIX_SIZE][MATRIX_SIZE];

extern unsigned char cypherKey[MATRIX_SIZE][MATRIX_SIZE];

//helper for mixColumn()
unsigned char galoisFieldMul(unsigned char c1, unsigned char c2);

//encryption states
void byteSub(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void shiftRow(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void shiftColumns(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void addRoundKey(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE], int round, unsigned char key[11][MATRIX_SIZE][MATRIX_SIZE]);

//encryption
void encrypt(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);

//decryption states
void inverseByteSub(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void inverseShiftRow(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void inverseShiftColumns(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);

//decryption
void decrypt(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
string decryptedMessage(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);

//key scheduling
void getRoundKey(unsigned char keys[11][MATRIX_SIZE][MATRIX_SIZE]);

#endif
