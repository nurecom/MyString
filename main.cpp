#include <iostream>
#include "String.h"

int String::countStrings{ 0 }; // Initializing a static field

void draw(int counter);

int main()
{	
	setlocale(LC_ALL, "Russian");
	std::cout << "\t\t\tTask ¹9 " << std::endl;
	draw(80);
	// Initializes strings of arbitrary lengt
	String str  ("Hello,");
	String str2 (" World");
	std::cout << "\tObject instance str  => ";
	str.Print();
	std::cout << "\tObject instance str2  => ";
	str2.Print();

	// Initializes a string with a maximum length of 80 characters
	String str3;

	// Copies the value of an instance of the str object to str3
	str3 = str2;
	std::cout << "\tA copy of an instance of the str2 object in str3 => ";
	str3.Print();

	// concatenation of str and str2 strings
	String result = str + str2;
	std::cout << "\tConcatenation str è str2  result => ";
	result.Print();

	std::cout << std::endl;

	std::cout <<"\tString length str =>" << str.Length() << std::endl;
	std::cout <<"\tString length str2 =>" << str2.Length() << std::endl;
	std::cout <<"\tString length result => " << result.Length() << std::endl;
	draw(80);
	std::cout <<"\tChecking for string equality str è str2  :" << (str == str2) << "\n";
	std::cout <<"\tChecking for row inequality str è str2  :" << (str != str2) << "\n";
	draw(80);
	std::cout << "\tChecking for string equality str2 è str3  :" << (str2 == str3) << "\n";
	std::cout << "\tChecking for row inequality str2 è str3  :" << (str2 != str3) << "\n";
	draw(80);
	std::cout <<"\tChanging the character in the string str" << "\n";
	std::cout << "\t";
	str.Print();	
	str[0] = 'Q';
	std::cout << std::endl;
	std::cout << "\t";
	str.Print();
	draw(80);
	std::cout << "\t Output the total number of created rows => ";
	std::cout << String::countStrings << std::endl;

	return 0;
}

void draw(int counter) {
	for (int i = 0; i < counter; i++) {
		std::cout << "*";
	}
	std::cout << '\n';
}