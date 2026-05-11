// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int find_max_element(int** matrix, int n, int m) {
	int max_value = matrix[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(matrix + i) + j) > max_value) {
				max_value = *(*(matrix + i) + j);
			}
		}
	}
	return max_value;
}

int find_min_element(int** matrix, int n, int m) {
	int min_value = matrix[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(matrix + i) + j) < min_value) {
				min_value = *(*(matrix + i) + j);
			}
		}
	}
	return min_value;
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {

	if (matrix == nullptr || n <= 0 || m <= 0) {
		return 0;
	}

	int max = find_max_element(matrix, n, m);
	int min = find_min_element(matrix, n, m);

	int total_sum = 0;

	for (int j = 0; j < m; j++)
	{
		bool has_extreme = false;
		for (int i = 0; i < n; i++)
		{
			if (matrix[i][j] == max || matrix[i][j] == min) {
				has_extreme = true;
				break;
			}
		}

		if (has_extreme) {
			for (int i = 0; i < n; i++)
			{
				total_sum += matrix[i][j];
			}
		}

	}

	return total_sum;
}