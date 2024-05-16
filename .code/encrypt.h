#ifndef ENCRYPT_H
#define ENCRYPT_H

const int MATRIX_SIZE = 4;

//reference tables
extern unsigned char sBox[256];
extern unsigned char rCon[MATRIX_SIZE][MATRIX_SIZE];

extern unsigned char cypherKey[MATRIX_SIZE][MATRIX_SIZE];

//helper for mixColumn()
unsigned char galoisFieldMul(unsigned char c1, unsigned char c2);

//encryption states
void byteSub(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void shiftRow(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void mixColumn(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void addRoundKey(unsigned char matrix[MATRIX_SIZE][MATRIX_SIZE], int round, unsigned char key[11][MATRIX_SIZE][MATRIX_SIZE]);

//key scheduling
void getRoundKey(unsigned char *key, unsigned char keys[11][MATRIX_SIZE][MATRIX_SIZE]);

#endif