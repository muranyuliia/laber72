#include <iostream>
#include <climits>
#include "Windows.h"
using namespace std;

void fillMatrix(int** matrix, int k, int n) {
    // ���������� ������� ����������� ���������� (����� ������� �� �������� ����������� ��� ����)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100; // �������� �������� �� 0 �� 99
        }
    }
}

void printMatrix(int** matrix, int k, int n) {
    // ��������� ������� �� �����
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
            int* minInEvenCol = new int[n / 2](); // ̳�������� ������� ������� ������� �������
            int* maxInOddCol = new int[n / 2](); // ������������ ������� ������� ��������� �������

            // ����������� ���������� �������� ��� ������� ������� ������� �� ������������� ��� ���������
            for (int col = 0; col < n; col++) {
                if (col % 2 == 0) { // ������ ��������
                    if (matrix[i][col] < minInEvenCol[col / 2] || minInEvenCol[col / 2] == 0) {
                        minInEvenCol[col / 2] = matrix[i][col];
                    }
                }
                else { // �������� ��������
                    if (matrix[i][col] > maxInOddCol[col / 2]) {
                        maxInOddCol[col / 2] = matrix[i][col];
                    }
                }
            }

            // ̳����� ������ ��������� ������� ������� ������� ������� � ������������ ��������� ������������ ��������� �������
            for (int col = 0; col < n; col += 2) {
                // ��������� ������ ��������� �������
                int oddColIndex = (col > 0) ? col - 1 : n - 1;
                // ̳����� ������ ��������
                swap(matrix[i][col], matrix[i][oddColIndex]);
            }

            delete[] minInEvenCol;
            delete[] maxInOddCol;

            // ����������� ������ ��� ���������� �����
            swapMinMaxInColumnsRecursive(matrix, k, n, i + 1, 0);
        }
        else {
            // ����������� ������ ��� ���������� �����
            swapMinMaxInColumnsRecursive(matrix, k, n, i + 1, 0);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int k, n;

    cout << "������ ������� ����� (k): ";
    cin >> k;
    cout << "������ ������� �������� (n): ";
    cin >> n;

    int** matrix = new int* [k];
    for (int i = 0; i < k; i++) {
        matrix[i] = new int[n];
    }

    fillMatrix(matrix, k, n);

    cout << "��������� �������:" << endl;
    printMatrix(matrix, k, n);

    swapMinMaxInColumnsRecursive(matrix, k, n, 0, 0);

    cout << "������� ���� ����� ������ � ���������:" << endl;
    printMatrix(matrix, k, n);

    for (int i = 0; i < k; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
