#pragma once
#include <iostream>

class String
{
	char* str; // Строка
	int length; // Длина строки

public:
	static int countStrings; // Статическое поле : счетчик созданных строк

	// Конструктор без параметров, инициализирует строку длиной 80 символов
	String()
	{
		str = nullptr;
		length = 80;
		countStrings++;

	}
	String(const char* str)
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

	// Функция перемещения

	String(String&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
	// Деструктор 
	~String() {
		delete[] this->str;
	};

	// Конструктор копирования

	String(const String& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	// Перегруженный оператор присваивания

	String& operator = (const String& other)
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

	// Перегруженный оператор сложения 

	String operator +(const String& other)
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

	// Выводит строку в консоль
	
	void Print()
	{
		std::cout << this->str << std:: endl;
	}

	int Length()
	{

		return length;
	}
	// Сравнение строк на идентичность

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

	// Сравнение строк на неравенство

	bool operator != (const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator [] (int index)
	{
		return this->str[index];
	}
};


