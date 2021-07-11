#include "String.h"

// Constructor without parameters, initializes a string with a length of 80 characters
String::String() : str {nullptr}, length {80}
{
	countStrings++;
}
// Constructor with parameteres
String::String(const char* str)
{
	length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
	countStrings++;
}
// Destructor
String::~String()
{
	delete[] this->str;
}
// Copy Constructor
String::String(const String& other)
{
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';	
}
//  Moving function
String::String(String&& other)
{
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}
// Overloaded assignment operator
String& String::operator=(const String& other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';

	return *this;
}
// Overloaded addition operator
String String::operator+(const String& other)
{
	String newStr;

	int thisLength = strlen(this->str);
	int otherLength = strlen(other.str);
	newStr.length = thisLength + otherLength;
	newStr.str = new char[thisLength + otherLength + 1];
	int i = 0;
	for (; i < thisLength; i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < otherLength; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}
	newStr.str[thisLength + otherLength] = '\0';
	return newStr;
}

