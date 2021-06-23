#include <iostream>
#include "String.h"

int String::countStrings{ 0 }; // Инициализация статического поля

void draw(int counter);

int main()
{	
	setlocale(LC_ALL, "Russian");
	std::cout << "\tЗадание №3 Тема: Статические переменные-члены и функции-члены, различные способы инициализации " << std::endl;
	draw(80);
	// Инициилизирует строки произвольной длины 
	String str  ("Hello,");
	String str2 (" World");
	std::cout << "\tЭкземпляр объекта str  => ";
	str.Print();
	std::cout << "\tЭкземпляр объекта str2  => ";
	str2.Print();

	// Инициилизирует строку длиной максимум 80 символов
	String str3;

	// Копирует значение экземпляра объекта str в str3
	str3 = str2;
	std::cout << "\tКопия экземпляра объекта str2 в str3 => ";
	str3.Print();

	// конкатенация строк str и str2
	String result = str + str2;
	std::cout << "\tКонкатенация str и str2  result => ";
	result.Print();

	std::cout << std::endl;

	std::cout <<"\tДлина строки str =>" << str.Length() << std::endl;
	std::cout <<"\tДлина строки str2 =>" << str2.Length() << std::endl;
	std::cout <<"\tДлина строки result => " << result.Length() << std::endl;
	draw(80);
	std::cout <<"\tПроверка на равенство строк str и str2  :" << (str == str2) << "\n";
	std::cout <<"\tПроверка на неравенство строк str и str2  :" << (str != str2) << "\n";
	draw(80);
	std::cout << "\tПроверка на равенство строк str2 и str3  :" << (str2 == str3) << "\n";
	std::cout << "\tПроверка на неравенство строк str2 и str3  :" << (str2 != str3) << "\n";
	draw(80);
	std::cout <<"\tМеняем символ в строке str" << "\n";
	std::cout << "\t";
	str.Print();	
	str[0] = 'Q';
	std::cout << std::endl;
	std::cout << "\t";
	str.Print();
	draw(80);
	std::cout << "\t Выводим общее количество созданных строк => ";
	std::cout << String::countStrings << std::endl;

	return 0;
}

void draw(int counter) {
	for (int i = 0; i < counter; i++) {
		std::cout << "*";
	}
	std::cout << '\n';
}