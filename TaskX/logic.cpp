// Task X [The matrix compression]
// Сжатие матрицы 
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо спроектировать эффективный алгоритм и разработать функцию, 
// которая уплотняет заданную матрицу, удаляя из нее строки 
// и столбцы, полностью заполненные нулями, т.е. нулевые строки 
// и/или столбцы. 
// Не забудьте про механизм "защиты от дурака".
//
// На базе разработанной функции реализовать тестовый или полноценный
// проект для демонстрации правильности работы алгоритма функции.
#include "logic.h"

bool is_row_empty(int** matrix, int i, int m) {
    for (int j = 0; j < m; ++j) {
        if (*(*(matrix + i) + j) != 0) {
            return false;
        }
    }
    return true;
}

bool is_column_empty(int** matrix, int j, int n) {
    for (int i = 0; i < n; ++i) {
        if (*(*(matrix + i) + j) != 0) {
            return false;
        }
    }
    return true;
}

int** compress_matrix(int** matrix, int n, int m, int* new_n, int* new_m) {

    if (new_n == nullptr || new_m == nullptr) return nullptr;
    if (matrix == nullptr || n <= 0 || m <= 0) {
        *new_n = 0;
        *new_m = 0;
        return nullptr;
    }

    int final_rows = 0;
    for (int i = 0; i < n; ++i) {
        if (is_row_empty(matrix, i, m) == false) {
            final_rows++;
        }
    }

    int final_columns = 0;
    for (int j = 0; j < m; ++j) {
        if (is_column_empty(matrix, j, n) == false) {
           
            final_columns++;
        }
    }

    *new_n = final_rows;
    *new_m = final_columns;

    if (final_rows == 0 || final_columns == 0) {
        *new_n = 0;
        *new_m = 0;
        return nullptr;
    }

    int** new_matrix = new int* [final_rows];
    for (int i = 0; i < final_rows; ++i) {
        *(new_matrix + i) = new int[final_columns];
    }

    int new_i = 0;
    for (int i = 0; i < n; ++i) {
        if (is_row_empty(matrix, i, m) == false) {
            int new_j = 0;
            for (int j = 0; j < m; ++j) {
                if (is_column_empty(matrix, j, n) == false) {
                    *(*(new_matrix + new_i) + new_j) = *(*(matrix + i) + j);
                    new_j++;
                }
            }
            new_i++;
        }
        
    }

    
    return new_matrix;
}