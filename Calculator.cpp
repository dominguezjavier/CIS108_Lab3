#include <iostream>
#include "calculator.h"


using namespace std;
double memory;

double addition(double first_number,  double second_number)
{
	return first_number + second_number;
}

double subtraction(double first_number, double second_number)
{
	return first_number - second_number;
}

double multiplication(double first_number, double second_number)
{
	return first_number * second_number;
}

double division(double first_number, double second_number)
{
	return first_number / second_number;
}

double powerfunction(double first_number, double second_number)
{
	return pow(first_number, second_number);;
}

void memorystore(double input_number)
{
	memory = input_number;
}

double memoryrecall()
{
	return memory;
}

void memoryclear()
{
	memory = 0;
}

double invertsign(double input_number)
{
	return 0.0 - input_number;;
}
