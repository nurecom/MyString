#include <iostream>
#include "String.h"

int String::countStrings{ 0 }; // ������������� ������������ ����

void draw(int counter);

int main()
{	
	setlocale(LC_ALL, "Russian");
	std::cout << "\t������� �3 ����: ����������� ����������-����� � �������-�����, ��������� ������� ������������� " << std::endl;
	draw(80);
	// �������������� ������ ������������ ����� 
	String str  ("Hello,");
	String str2 (" World");
	std::cout << "\t��������� ������� str  => ";
	str.Print();
	std::cout << "\t��������� ������� str2  => ";
	str2.Print();

	// �������������� ������ ������ �������� 80 ��������
	String str3;

	// �������� �������� ���������� ������� str � str3
	str3 = str2;
	std::cout << "\t����� ���������� ������� str2 � str3 => ";
	str3.Print();

	// ������������ ����� str � str2
	String result = str + str2;
	std::cout << "\t������������ str � str2  result => ";
	result.Print();

	std::cout << std::endl;

	std::cout <<"\t����� ������ str =>" << str.Length() << std::endl;
	std::cout <<"\t����� ������ str2 =>" << str2.Length() << std::endl;
	std::cout <<"\t����� ������ result => " << result.Length() << std::endl;
	draw(80);
	std::cout <<"\t�������� �� ��������� ����� str � str2  :" << (str == str2) << "\n";
	std::cout <<"\t�������� �� ����������� ����� str � str2  :" << (str != str2) << "\n";
	draw(80);
	std::cout << "\t�������� �� ��������� ����� str2 � str3  :" << (str2 == str3) << "\n";
	std::cout << "\t�������� �� ����������� ����� str2 � str3  :" << (str2 != str3) << "\n";
	draw(80);
	std::cout <<"\t������ ������ � ������ str" << "\n";
	std::cout << "\t";
	str.Print();	
	str[0] = 'Q';
	std::cout << std::endl;
	std::cout << "\t";
	str.Print();
	draw(80);
	std::cout << "\t ������� ����� ���������� ��������� ����� => ";
	std::cout << String::countStrings << std::endl;

	return 0;
}

void draw(int counter) {
	for (int i = 0; i < counter; i++) {
		std::cout << "*";
	}
	std::cout << '\n';
}