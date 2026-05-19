// Минимальный максимум среди всех локальных максимумов
// [The minimum maximum among all local maxima].
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// находит значение локального максимума, который является
// минимальным среди всех локальных максимумов. 

#include "logic.h"

int get_min_maximum(int** matrix, int n, int m) {

   
    if (!matrix || n <= 0 || m <= 0 || (n == 1 && m == 1)) {
        return 0;
    }

    
    bool found_any = false;
    int min_max_value = 0;

   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

           
            int current = *(*(matrix + i) + j);
            bool is_max = true;

           
            if (i > 0 && current <= *(*(matrix + (i - 1)) + j)) {
                is_max = false;
            }
            if (i < n - 1 && current <= *(*(matrix + (i + 1)) + j)) {
                is_max = false;
            }
            if (j > 0 && current <= *(*(matrix + i) + (j - 1))) {
                is_max = false;
            }
            if (j < m - 1 && current <= *(*(matrix + i) + (j + 1))) {
                is_max = false;
            }

            
            if (is_max) {
                
                if (!found_any) {
                    min_max_value = current;
                    found_any = true;
                }
                else if (current < min_max_value) {
                    min_max_value = current;
                }
            }
        }
    }

   
    return found_any ? min_max_value : 0;
}
