#pragma once
#include "AbstrBook.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

class Book :
	public AbstrBook													//Наследуем от абстрактного класса (от интерфейса?)
{
private:
	std::string Title;													//Название книги
	std::string Author;													//Автор
	bool inLib;															//Наличие в библиотеке (да или нет)

	static AbstrBook** Array;											//массив указателей на объекты родительского класса
	static int objCount;												//количество проинициализированных объектов
	static int arraySize;												//Размер массива для хранения указателей
public:
	Book();																//Конструктор по умолчанию
	//Book(std::string, std::string, bool);								//Конструктор с параметрами

	~Book();															//Деструктор

	virtual void printBook() const;										//Реализация метода вывода на экран из Абстрактного класса
	
	static void showArray();
	static void clearArray();
	static void delElem(int n);

private:
	static void checkArray();											//Метод проверки на наличие свободных мест в массиве

};

