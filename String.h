#pragma once
#include <iostream>

class String
{
	char* str; // String
	int length; // String length

public:
	static int countStrings; // Static field: counter of created rows

	// Constructor without parameters, initializes a string with a length of 80 characters
	String();
	// Constructor with parameteres
	String(const char* str);
	// Destructor
	~String();
	// Copy Constructor
	String(const String& other);
	//  Moving function
	String(String&& other);
	// Overloaded assignment operator
	String& operator = (const String& other);
	// Overloaded addition operator
	String operator +(const String& other);
	// Outputs a string to the console
	void Print()
	{
		std::cout << str << std::endl;
	}
	// String Length
	int Length()
	{
		return length;
	}
	// Comparing strings for identity

	bool operator == (const String& other)
	{
		if (this->length != other.length)
		{
			return false;
		}
		for (int i = 0; i < length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}

		return true;

	}

	//  Comparing rows for inequality

	bool operator != (const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator [] (int index)
	{
		return this->str[index];
	}
};


