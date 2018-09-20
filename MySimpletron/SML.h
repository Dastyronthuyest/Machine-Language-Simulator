#pragma once

#ifndef SML_H
#define SML_H

class SML
{
public:
	SML();
	~SML();
	int select();
	void read();
	void write();
	void load();
	void store();
	void add();
	void substract();
	void divide();
	void multiply();
	void branch();
	void branchneg();
	void branchzero();
	void halt();
	int initial();
	int step();
	int pass();

private:
	int memory[100];
	int accumulator;
	int instructionCounter;
	int operationCode;
	int operand;
	int instructionRegister;
};

#endif
