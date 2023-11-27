#include <iostream>
#include <ctime>

using namespace std;

void createMatrix(int** matrix, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int x = rand() % 201 - 100;
            matrix[i][j] = x;
        }
    }
}

void multiplyMatrices(int** result, int** matrix1, int rows1, int cols1, int** matrix2, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            cout << result[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int numRows1, numCols1, numRows2, numCols2;
    cout << "row1: ";
    cin >> numRows1;
    cout << "column1: ";
    cin >> numCols1;
    cout << "row2: ";
    cin >> numRows2;
    cout << "column2: ";
    cin >> numCols2;

    if (numCols1 == numRows2) {
        int** matrix1 = new int*[numRows1];
        for (int i = 0; i < numRows1; ++i) {
            matrix1[i] = new int[numCols1];
        }

        int** matrix2 = new int*[numRows2];
        for (int i = 0; i < numRows2; ++i) {
            matrix2[i] = new int[numCols2];
        }

        int** result = new int*[numRows1];
        for (int i = 0; i < numRows1; ++i) {
            result[i] = new int[numCols2];
        }

        createMatrix(matrix1, numRows1, numCols1);
        createMatrix(matrix2, numRows2, numCols2);

        multiplyMatrices(result, matrix1, numRows1, numCols1, matrix2, numCols2);

        // Освобождение памяти
        for (int i = 0; i < numRows1; ++i) {
            delete[] matrix1[i];
        }
        delete[] matrix1;

        for (int i = 0; i < numRows2; ++i) {
            delete[] matrix2[i];
        }
        delete[] matrix2;

        for (int i = 0; i < numRows1; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return 0;
    } else {
        cout << "These matrices cannot be multiplied\n";
    }
}