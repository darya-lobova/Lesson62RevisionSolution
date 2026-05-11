// Сумма элементов [The sum of elements]
// 
// Дана математическая квадратная матрица размером N.
// Необходимо разработать функцию (или программу), 
// которая вычисляет сумму элементов матрицы, 
// расположенных на главной и побочной диагоналях.
#include "logic.h"

int sum_main_diagonales_elements(int** matrix, int n) {

	if (matrix == nullptr || n <= 0) {
		return 0;
	}

	int sum_main = 0;

	for (int i = 0; i < n; i++)
	{
		sum_main += *(*(matrix + i) + i);

	}
	

	return sum_main;
}

int sum_second_diagonales_elements(int** matrix, int n) {
	
	if (matrix == nullptr || n <= 0) {
		return 0;
	}

	int sum_second = 0;
	int central_element = matrix[n/2][n/2];

	for (int i = 0; i < n; i++)
	{
		sum_second += *(*(matrix + i) + n - 1 - i);
		if (n % 2 != 0) {
			sum_second - central_element;
		}
	}

	return sum_second ;
}


int sum_main_and_second_diagonales_elements(int** matrix, int n) {
	
	if (n == 1) {
		return *(*(matrix + 0) + 0);
	}

	int sum_main = sum_main_diagonales_elements(matrix, n);
	int sum_second = sum_second_diagonales_elements(matrix, n);

	int sum = sum_main + sum_second;

	return sum;
}