#include <iostream>
#include <climits>
#include "Windows.h"
using namespace std;

void fillMatrix(int** matrix, int k, int n) {
    // «аповненн€ матриц≥ випадковими значенн€ми (можна зам≥нити на введенн€ користувача або ≥нше)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100; // ¬ипадков≥ значенн€ в≥д 0 до 99
        }
    }
}

void printMatrix(int** matrix, int k, int n) {
    // ¬иведенн€ матриц≥ на екран
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void swapMinMaxInColumnsRecursive(int** matrix, int k, int n, int i, int j) {
    if (i < k) {
        if (j < n) {
            int* minInEvenCol = new int[n / 2](); // ћ≥н≥мальний елемент кожного парного стовпц€
            int* maxInOddCol = new int[n / 2](); // ћаксимальний елемент кожного непарного стовпц€

            // «находженн€ м≥н≥мального елемента дл€ кожного парного стовпц€ та максимального дл€ непарного
            for (int col = 0; col < n; col++) {
                if (col % 2 == 0) { // ѕарний стовпець
                    if (matrix[i][col] < minInEvenCol[col / 2] || minInEvenCol[col / 2] == 0) {
                        minInEvenCol[col / 2] = matrix[i][col];
                    }
                }
                else { // Ќепарний стовпець
                    if (matrix[i][col] > maxInOddCol[col / 2]) {
                        maxInOddCol[col / 2] = matrix[i][col];
                    }
                }
            }

            // ћ≥н€Їмо м≥сц€ми м≥н≥мальний елемент кожного парного стовпц€ з максимальним елементом попереднього непарного стовпц€
            for (int col = 0; col < n; col += 2) {
                // «находимо ≥ндекс непарного стовпц€
                int oddColIndex = (col > 0) ? col - 1 : n - 1;
                // ћ≥н€Їмо м≥сц€ми елементи
                swap(matrix[i][col], matrix[i][oddColIndex]);
            }

            delete[] minInEvenCol;
            delete[] maxInOddCol;

            // –екурсивний виклик дл€ наступного р€дка
            swapMinMaxInColumnsRecursive(matrix, k, n, i + 1, 0);
        }
        else {
            // –екурсивний виклик дл€ наступного р€дка
            swapMinMaxInColumnsRecursive(matrix, k, n, i + 1, 0);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int k, n;

    cout << "¬вед≥ть к≥льк≥сть р€дк≥в (k): ";
    cin >> k;
    cout << "¬вед≥ть к≥льк≥сть стовпц≥в (n): ";
    cin >> n;

    int** matrix = new int* [k];
    for (int i = 0; i < k; i++) {
        matrix[i] = new int[n];
    }

    fillMatrix(matrix, k, n);

    cout << "ѕочаткова матриц€:" << endl;
    printMatrix(matrix, k, n);

    swapMinMaxInColumnsRecursive(matrix, k, n, 0, 0);

    cout << "ћатриц€ п≥сл€ обм≥ну м≥н≥мум≥в ≥ максимум≥в:" << endl;
    printMatrix(matrix, k, n);

    for (int i = 0; i < k; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
