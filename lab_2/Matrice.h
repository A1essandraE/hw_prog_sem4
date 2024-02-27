#include <iostream>
#include <stdlib.h>

class Matrix {
private:
    int** data;  //двумерный массив
    unsigned int m;  //кол-во строк
    unsigned int n;  //кол-во столбцов
public:
    Matrix(int righe, int colonne);
    ~Matrix();
    Matrix operator+(const Matrix& matrice);
    Matrix operator-(const Matrix& matrice);
