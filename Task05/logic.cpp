// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

void get_last_local_minimum(int** matrix, int n, int m, int* ii, int* jj) {
    *ii = 0;
    *jj = 0;

    if (!matrix || n <= 0 || m <= 0) {
        return;
    }

    if (n == 1 && m == 1) {
        return;
    }

   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            int current = *(*(matrix + i) + j);
            bool is_min = true;

            if (i > 0 && current >= *(*(matrix + (i - 1)) + j)) {
                is_min = false;
            }
            if (i < n - 1 && current >= *(*(matrix + (i + 1)) + j)) {
                is_min = false;
            }
            if (j > 0 && current >= *(*(matrix + i) + (j - 1))) {
                is_min = false;
            }
            if (j < m - 1 && current >= *(*(matrix + i) + (j + 1))) {
                is_min = false;
            }


            if (is_min) {
                *ii = i + 1;
                *jj = j + 1;
            }
        }
    }
}
