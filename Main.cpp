#include <iostream>
#include "calculator.h"
#include <Conio.h>
#include <string>

using namespace std;


// When this is true, we are working on the right value
using namespace std;

double first_number_for_the_operation, second_number_for_the_operation;
string keys_before_the_operation_typed, keys_after_the_operation_typed;
int active_number;
char operation_in_progress, key_pressed;
bool decimal_key_is_pressed;


void start() {
	cout << "welcome to my calculator";
}

void resetVariables()
{
	keys_before_the_operation_typed = "";
	keys_after_the_operation_typed = "";
	first_number_for_the_operation = 0;
	second_number_for_the_operation = 0;
	active_number = 1;
	decimal_key_is_pressed = false;
}



int main()
{
	cout << "> ";
	resetVariables();
//Still having alot of trouble figuring this out. I had to refernce basili's and tranculent's code to barely make it through.

	do
	{

		key_pressed = toupper(char(_getch())); // get the key pressed, convert it to char and to upper case of the key pressed

		switch (key_pressed)
		{
			// if the digit or dot is pressed
		case '1': case '2': case'3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case'.':
			if ((key_pressed != '.') || (key_pressed == '.' && !decimal_key_is_pressed))
			{
				if (active_number == 1)
					keys_before_the_operation_typed += key_pressed;
				else
					keys_after_the_operation_typed += key_pressed;
				cout << key_pressed;
			}
			if (key_pressed == '.')
				decimal_key_is_pressed = true;
			break;

			// if some of the operation key is pressed
		case '*': case '+': case '-': case '/': case '^':
			if (active_number == 1)
			{
				first_number_for_the_operation = stod(keys_before_the_operation_typed);
				active_number = 2;
				keys_before_the_operation_typed = "";
				keys_after_the_operation_typed = "";
			}
			cout << key_pressed;
			operation_in_progress = key_pressed;
			break;

			// if "Enter" is pressed
			case char(13) :
				cout << endl;
				if (keys_after_the_operation_typed != "")
				{
					second_number_for_the_operation = stod(keys_after_the_operation_typed); // get the keys after operation key pressed as second number

					// do a neccessary operation that depends of a key that is earlier pressed as a operation key, and put the result in first number double variable
					switch (operation_in_progress)
					{
					case '+':
						first_number_for_the_operation = addition(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '-':
						first_number_for_the_operation = subtraction(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '*':
						first_number_for_the_operation = multiplication(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '/':
						first_number_for_the_operation = division(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '^':
						first_number_for_the_operation = powerfunction(first_number_for_the_operation, second_number_for_the_operation);
						break;
					default:
						break;
					}
				}
				cout << first_number_for_the_operation << endl << "> "; // print the result
				keys_before_the_operation_typed = to_string(first_number_for_the_operation); // put first number back in the string before the operation
				keys_after_the_operation_typed = ""; // clear the 'after the operation' string 
				active_number = 1; // set active number as first
				break;

				// if "S" is pressed
			case 'S':
				memorystore(first_number_for_the_operation); 
				break;

				// if "R" is pressed
			case 'R':
				first_number_for_the_operation = memoryrecall(); 
				cout << endl << first_number_for_the_operation; 
				break;

				
			case 'M':
				memoryclear();
				break;

				
			case 'I':
				first_number_for_the_operation = invertsign(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will invert it
				cout << endl << first_number_for_the_operation; // and use it as a first number
				break;

				// if "C" is pressed
			case 'C':
				cout << endl << "> "; // print the default char in a new row;
				resetVariables(); // reset all variables
				break;


			default:
				break;
		}

	} while (key_pressed != 'X');

	return 0;
}





