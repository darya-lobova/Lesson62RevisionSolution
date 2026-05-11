// Количество строк с большим количество положительных элементов
// [The Number of rows with a large number of positive elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию(или программу), которая находит
// количество строк, в которых положительных элементов больше 
// чем всех остальных (отрицательных и нулевых).

#include "logic.h"

int count_positive_values(int** matrix, int n, int m) {
	if (matrix == nullptr, n <= 0, m <= 0) {
		return 0;
	}

	int count_positive = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(matrix + i) + j) > 0) {
				count_positive++;
			}
		}
	}
	return count_positive;

}

int count_rows_with_more_positive_values(int** matrix, int n, int m) {

	if (matrix == nullptr, n <= 0, m <= 0) {
		return 0;
	}

	int all_elements = n - 1;
	int count_positive = count_positive_values(matrix, n, m);
	int count_rows = 0;

	for (int i = 0; i < n; i++)
	{
			if (all_elements - count_positive < count_positive) {
				count_rows++;
			}
	}

	return count_rows;

}