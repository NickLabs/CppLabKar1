#include <iostream>
#include <fstream>
#include "BinaryMatrix.h"
#include <string>
#include "Algorithm.h"
#include "Interface.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	
	cout << endl << "Работу выполнил студент 465 группы" << endl;
	cout << "Винокуров Н.А" << endl;
	cout << "Данная программа предназначена для поиска в тексте" << endl;
	cout << "Повторяющихся символов и их замены на сигнатуру вида" << endl;
	cout << "{Символ,кол-во повторений} с возможностью восстановить" << endl;
	cout << "Исходную послдовательность" << endl;
	main_menu();


	system("pause");
	return 0;
}