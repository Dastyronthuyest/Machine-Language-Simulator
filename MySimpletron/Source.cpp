#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
using std::left;
using std::right;
using std::setfill;
#include "SML.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	SML model;
	if (model.pass() == 1)
	{
		return 1;
	}

	system("pause");
	return 0;
}