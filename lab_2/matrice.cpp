
#include <iostream>
#include <stdlib.h>

class Matrix {
public:
    int** data;  //двумерный массив
    unsigned int m;  //кол-во строк
    unsigned int n;  //кол-во столбцов

    // конструкор
    Matrix(int righe, int colonne) {
        m = righe;
        n = colonne;
        data = new int*[righe];
        for (int i = 0; i < righe; i++) {
            data[i] = new int[colonne];
        }
    }

    // дуструктор
    ~Matrix() {
        delete[] data;
    }
 
    //заполняем случайными числами от 0 до 9
    void fillRandom(void) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = rand() % 10;
            }
        }
    }

    Matrix operator+(const Matrix& matrice) {
        Matrix temp(m, n);
        if (m == matrice.m && n == matrice.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    temp.data[i][j] = data[i][j] + matrice.data[i][j];
                }
            }
        }
        else {
            std::cout << "ERROR! The size of the given matrices doesn't match. All the values will be reduced to 0." << std::endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    temp.data[i][j] = NULL;
                }
            }
        }
        return temp;
    }

    Matrix operator-(const Matrix& matrice) {
        Matrix temp(m, n);
        if (m == matrice.m && n == matrice.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    temp.data[i][j] = data[i][j] - matrice.data[i][j];
                }
            }
        }
        else {
            std::cout << "ERROR! The size of the given matrices doesn't match. All the values will be reduced to 0." << std::endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    temp.data[i][j] = NULL;
                }
            }
        }
        return temp;
    }
};

//перезагружаем оператор<<
std::ostream& operator<<(std::ostream& out, const Matrix& matrice) {
    for (int i = 0; i < matrice.m; i++) {
        for (int j = 0; j < matrice.n; j++) {
            std::cout << matrice.data[i][j] << "\t";
        }
        std::cout << "\n";
    }
    return out;
}



int main() {
    Matrix matriceUno(6, 6);
    Matrix matriceDue(6, 6);
    Matrix matriceTre(6, 2);
    Matrix matriceQuattro(3, 6);

    matriceUno.fillRandom();
    matriceDue.fillRandom();
    matriceTre.fillRandom();
    matriceQuattro.fillRandom();

    std::cout << "First Matrix: " << std::endl;
    std::cout << matriceUno << std::endl;
    std::cout << "Second Matrix: " << std::endl;
    std::cout << matriceDue << std::endl;
    std::cout << "Third Matrix: " << std::endl;
    std::cout << matriceTre << std::endl;
    std::cout << "Fourth Matrix: " << std::endl;
    std::cout << matriceQuattro << std::endl;

    std::cout << "The sum of the first and second matrices: " << std::endl;
    std::cout << matriceUno + matriceDue << std::endl;
    std::cout << "The difference between the first and second matrices: " << std::endl;
    std::cout << matriceUno - matriceDue << std::endl;

    
    return 0;
}
