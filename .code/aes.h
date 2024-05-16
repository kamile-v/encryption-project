#ifndef AES_H
#define AES_H

const int BLOCK_SIZE = 4;

//reference tables
extern unsigned char sBox[256];
extern unsigned char rCon[BLOCK_SIZE][BLOCK_SIZE];

//helper for mixColumn()
unsigned char galoisFieldMul(unsigned char c1, unsigned char c2);

//encryption states
void byteSub(unsigned char matrix[BLOCK_SIZE][BLOCK_SIZE]);
void shiftRow(unsigned char matrix[BLOCK_SIZE][BLOCK_SIZE]);
void mixColumn(unsigned char matrix[BLOCK_SIZE][BLOCK_SIZE]);
void addRoundKey(unsigned char matrix[BLOCK_SIZE][BLOCK_SIZE], unsigned char key[BLOCK_SIZE][BLOCK_SIZE]);

#endif