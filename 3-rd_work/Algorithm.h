#pragma once
#include <iostream>
#include <fstream>
#include "BinaryMatrix.h"
#include <cstring>

using namespace std;

struct Cordinates{
	int row;
	int column;
};

struct AllCordinates {
	Cordinates* cordinates;
	int size;
};

AllCordinates solution(BinaryMatrix bm);