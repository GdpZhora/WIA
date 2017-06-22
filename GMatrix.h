#ifndef GMATRIX_H
#define GMATRIX_H


BOOL LoadGameMatrix();
int getValueGMatrix(float x, float z);
int getValueGMatrixZ(int i, int j);
D3DXVECTOR3 StartGame();
D3DXVECTOR3 PosGame(int i, int j);
float StartUgol();
void setValueGMatrix(int x, int y, int value);
int getValueGMatrixSK(float x, float z,int* i,int* j);
#endif