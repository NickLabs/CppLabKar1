#include "BinaryMatrix.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


using namespace std;

BinaryMatrix::BinaryMatrix(ifstream &file_input)
{
	int count_space = 0;
	char symbol;

	file_input.seekg(0, ios::beg);
	file_input.clear();

	while (!file_input.eof())
	{
		file_input.get(symbol);
		if (symbol == ' ') count_space++;
		if (symbol == '\n') break;
	}
	this->size = count_space + 1;

	file_input.seekg(0, ios::beg);
	file_input.clear();

	this->matrix = new int*[size];
	for (int i = 0; i < this->size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < this->size; j++) {
			file_input >> this->matrix[i][j];
		}
	}
}

BinaryMatrix::BinaryMatrix(int size)
{
	this->size = size;
	this->matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		this->matrix[i] = new int[size];
	}
}

void BinaryMatrix::print_matrix()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			cout << this->matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

int BinaryMatrix::getSize() {
	return this->size;
}

void BinaryMatrix::setMatrixElement(int row ,int column, int element) {
	this->matrix[row][column] = element;
}


void BinaryMatrix::print_matrix_to_file(ofstream &out) {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			out << this->matrix[i][j] << ' ';
		}
		out << endl;
	}
	out << endl;
	out.close();
}