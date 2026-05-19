#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void print(string s);
void init_random(int* matrix, int n, int m, int a, int b);
void init_user(int* matrix, int n, int m);
void clear(int* matrix, int n, int m);
int* create(int n, int m);
void remove(int* matrix);
string convert(int* matrix, int n, int m);
void print_compressed(int** matrix, int n, int m);