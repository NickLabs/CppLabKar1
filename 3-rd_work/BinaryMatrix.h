#pragma once
#include <iostream>
#include <string>

using namespace std;

class BinaryMatrix
{
private:
	int** matrix;
	int size;
public:
	BinaryMatrix(ifstream &file_input);
	BinaryMatrix(int size);
	int getSize();
	void setMatrixElement(int row, int column, int element);
	void print_matrix();
	void print_matrix_to_file(ofstream &out);
	int* operator[](int i) {
		return matrix[i];
	}
};