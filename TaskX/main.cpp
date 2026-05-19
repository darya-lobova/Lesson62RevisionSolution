#include "logic.h"


int main() {
    int* matrix;
    int n, m;
    int new_n = 0;
    int new_m = 0;

    cout << "Input size of square matrix (n x m): ";
    cin >> n >> m;

    matrix = create(n, m);
    if (matrix == nullptr) {
        cout << "Error: Memory allocation failed!" << endl;
        return 1;
    }

    init_random(matrix, n, m, 0, 1);
    cout << "Before: " << endl;

    print(convert(matrix, n, m) + "\n");

    int** matrix_ptr_array = new int* [n];
    for (int i = 0; i < n; ++i) {
        *(matrix_ptr_array + i) = (matrix + i * m);
    }

    cout << "After: " << endl;

    int** new_matrix = compress_matrix(matrix_ptr_array, n, m, &new_n, &new_m);

    print_compressed(new_matrix, new_n, new_m);

    if (new_matrix != nullptr) {
        for (int i = 0; i < new_n; ++i) {
            delete[] * (new_matrix + i);
        }
        delete[] new_matrix;
    }

   
    clear(matrix, n, m);
    remove(matrix);

    return 0;
}