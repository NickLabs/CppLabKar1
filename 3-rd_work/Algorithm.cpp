#include <iostream>
#include <fstream>
#include "BinaryMatrix.h"
#include <cstring>
#include "Algorithm.h"
#include "Interface.h"

using namespace std;

AllCordinates solution(BinaryMatrix bm) {
	int sqr_size = 0;
	int squares_found = 0;
	bool is_found = true;
	Cordinates* cord = new Cordinates[bm.getSize() * bm.getSize()];
	cout << "Введите размер искомого квадрата: ";
	sqr_size = correct_user_input(0, bm.getSize());
	for (int i = 0; i < bm.getSize() - sqr_size+1; i++) {
		for (int j = 0; j < bm.getSize() - sqr_size+1; j++) {
			if (bm[i][j] == 1) {
				is_found = true;
				int temp_i = i;
				int temp_j = j;
				int side_length = pow(2, sqr_size) / 4;
				for (int k = 0; k < 4; k++) {
					if (k == 0) {
						for (int c = 0; c < side_length; c++) {
							if (bm[temp_i][temp_j] == 0) {
								is_found = false;
							}
							temp_i++;
						}
						if (!is_found) { break; }
					}
					else if (k == 1) {
						for (int c = 0; c < side_length; c++) {
							if (bm[temp_i][temp_j] == 0) {
								is_found = false;
							}
							temp_j++;
						}
						if (!is_found) { break; }
					}
					else if (k == 2) {
						for (int c = 0; c < side_length; c++) {
							if (bm[temp_i][temp_j] == 0) {
								is_found = false;
							}
							temp_i--;
						}
						if (!is_found) { break; }
					}
					else {
						for (int c = 0; c < side_length; c++) {
							if (bm[temp_i][temp_j] == 0) {
								is_found = false;
							}
							temp_j--;
						}
						if (!is_found) { break; }
					}				
				}
				if (is_found) { 
					cord[squares_found].row = i; 
					cord[squares_found].column = j;
					squares_found++;
				}
			}
		}
	}
	AllCordinates cords;
	cords.cordinates = cord;
	cords.size = squares_found;
	return cords;
}
