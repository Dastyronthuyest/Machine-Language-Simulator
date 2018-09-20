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


SML::SML()
	: accumulator(0), instructionCounter(0), operationCode(0), operand(0), instructionRegister(0)
{
	for (int i = 0; i < 100; i++)
		memory[i] = 0;
}

SML::~SML()
{
	halt();
	system("pause");
}

int SML::select()
{
	switch (operationCode)
	{
	case 0:
		break;
	case 10:
		read();
		break;
	case 11:
		write();
		break;
	case 20:
		load();
		break;
	case 21:
		store();
		break;
	case 30:
		add();
		break;
	case 31:
		substract();
		break;
	case 32:
		divide();
		break;
	case 33:
		multiply();
		break;
	case 40:
		branch();
		return 3;
	case 41:
		branchneg();
		return 3;
	case 42:
		branchzero();
		return 3;
	case 43:
		halt();
		return 2;
	default:
		cout << "Incorrect operator" << endl;
		break;
	}
	return 0;
}

void SML::read()
{
	cout << "Введите слово для помещения по адресу #" << operand << ' ';
	cin >> memory[operand];
}

void SML::write()
{
	cout << "Cлово, содержащееся по адресу #" << operand << ": " << memory[operand] << endl;
}

void SML::load()
{
	accumulator = memory[operand];
	cout << "Cлово по адресу #" << operand << " помещено в аккумулятор" << endl;
}

void SML::store()
{
	memory[operand] = accumulator;
	accumulator = 0;
	cout << "Cлово по адресу #" << operand << " извлечено из аккумулятора" << endl;
}

void SML::add()
{
	accumulator += memory[operand];
	cout << "Cлово по адресу #" << operand << " прибавлено к значению в аккумуляторе" << endl;
}

void SML::substract()
{
	accumulator -= memory[operand];
	cout << "Cлово по адресу #" << operand << " вычтено из значения аккумуляторе" << endl;
}

void SML::divide()
{
	accumulator /= memory[operand];
	cout << "Значение в аккумуляторе разделено на слово по адресу #" << operand << endl;
}

void SML::multiply()
{
	accumulator *= memory[operand];
	cout << "Значение в аккумуляторе умножено на слово по адресу #" << operand << endl;
}

void SML::branch()
{
	instructionCounter = operand;
	cout << "Переход по адресу #" << operand << endl;
}

void SML::branchneg()
{
	if (accumulator < 0)
		instructionCounter = operand;
	cout << "Переход по адресу #" << operand << ", если в аккумуляторе отрицательное число" << endl;
}

void SML::branchzero()
{
	if (!accumulator)
		instructionCounter = operand;
	cout << "Переход по адресу #" << operand << ", если в аккумуляторе 0" << endl;
}

void SML::halt()
{
	cout << "\nРЕГИСТРЫ:\n" << setw(20) << left << "accumulator" << " +" << setfill('0') << setw(4) << right << accumulator << setfill(' ') << endl
		<< setw(20) << left << "instructionCounter" << "    " << setfill('0') << setw(2) << right << instructionCounter << setfill(' ') << endl
		<< setw(20) << left << "instructionRegister" << " +" << setfill('0') << setw(4) << right << instructionRegister << setfill(' ') << endl
		<< setw(20) << left << "operationCode" << "    " << setfill('0') << setw(2) << right << operationCode << setfill(' ') << endl
		<< setw(20) << left << "operand" << "    " << setfill('0') << setw(2) << right << operand << setfill(' ') << "\n\nПАМЯТЬ:\n"
		<< setw(8) << '0';

	for (int i = 1; i <= 9; i++)
		cout << setw(6) << i;
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		if (i == 0)
			cout << setw(2) << i;
		else if ((i % 10) == 0)
			cout << setw(2) << i;
		cout << " +" << setfill('0') << setw(4) << memory[i];
		if ((i % 10) == 9)
			cout << endl;
	}
}

int SML::initial()
{
	for (instructionCounter; instructionCounter < 100; instructionCounter++)
	{
		cout << setfill('0') << setw(2) << instructionCounter << setfill(' ') << "? ";
		cin >> memory[instructionCounter];

		if (memory[instructionCounter] < -9999 || memory[instructionCounter]>9999)
		{
			cout << "\nНе найдено определения\"" << memory[instructionCounter] << "\"";
			return 1;
		}

		if (!memory[instructionCounter])
			break;
	}
	cout << endl;
	instructionCounter = 0;
	return 0;
}

int SML::step()
{
	int flag = 0;

	instructionRegister = memory[instructionCounter];

	operationCode = instructionRegister / 100;
	operand = instructionRegister % 100;

	flag = select();
	if (flag == 2)
		return 1;
	else if (flag != 3)
		++instructionCounter;

	return 0;
}

int SML::pass()
{
	int err = initial();

	if (err == 1)
	{
		return 1;
	}

	for (int i = 0; memory[i] != 0; i++)
	{
		if (step() == 1)
		{
			break;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		memory[i] = 0;
	}

	accumulator = instructionCounter = operationCode = operand = instructionRegister = 0;
	return 0;
}