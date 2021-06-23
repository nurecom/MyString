#pragma once
#include <iostream>

class String
{
	char* str; // ������
	int length; // ����� ������

public:
	static int countStrings; // ����������� ���� : ������� ��������� �����

	// ����������� ��� ����������, �������������� ������ ������ 80 ��������
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

	// ������� �����������

	String(String&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
	// ���������� 
	~String() {
		delete[] this->str;
	};

	// ����������� �����������

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

	// ������������� �������� ������������

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

	// ������������� �������� �������� 

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

	// ������� ������ � �������
	
	void Print()
	{
		std::cout << this->str << std:: endl;
	}

	int Length()
	{

		return length;
	}
	// ��������� ����� �� ������������

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

	// ��������� ����� �� �����������

	bool operator != (const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator [] (int index)
	{
		return this->str[index];
	}
};


