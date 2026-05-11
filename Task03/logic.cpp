// Количество строк с большим количество положительных элементов
// [The Number of rows with a large number of positive elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию(или программу), которая находит
// количество строк, в которых положительных элементов больше 
// чем всех остальных (отрицательных и нулевых).

#include "logic.h"

int count_rows_with_more_positive_values(int** matrix, int n, int m) {
	if (matrix == nullptr || n <= 0 || m <= 0) {
		return 0;
	}
	int count_positive = 0; 

	for (int i = 0; i < n; i++)
	{
		int count = 0;

		for (int j = 0; j < m; j++)
		{
			if (*(*(matrix + i) + j) > 0) { 
				count++; 
			}
		}
		if ((m - count) < count) {
			count_positive++;
		}
	}
	return count_positive;
}