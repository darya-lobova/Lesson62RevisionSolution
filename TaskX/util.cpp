#include "util.h"

void print(string s) {
    cout << s;
}


void init_random(int* matrix, int n, int m, int a, int b) {
    if (matrix == NULL || n <= 0 || m <= 0) return;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            *(matrix + i * m + j) = rand() % (b - a + 1) + a;
        }
    }
}

void clear(int* matrix, int n, int m) {
    init_random(matrix, n, m, 0, 0);
}


int* create(int n, int m) {
    if (n <= 0 || m <= 0) {
        return NULL;
    }
    return new int[n * m];
}


void remove(int* matrix) {
    if (matrix != NULL) {
        delete[] matrix;
    }
}


string convert(int* matrix, int n, int m) {
    if (matrix == NULL || n <= 0 || m <= 0) {
        return "Empty matrix.\n";
    }

    string s = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += to_string(*(matrix + i * m + j)) + "\t";
        }
        s += "\n";
    }
    return s;
}


void init_user(int* matrix, int n, int m) {
    if (matrix == NULL || n <= 0 || m <= 0) return;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> *(matrix + i * m + j);
        }
    }
}

void print_compressed(int** matrix, int n, int m) {
    if (matrix == nullptr || n <= 0 || m <= 0) {
        cout << "Empty matrix.";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << "\n";
    }
}