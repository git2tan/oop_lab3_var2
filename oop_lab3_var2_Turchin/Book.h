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
	
	static void showArray();											//Метод вывода на экран всего массива объектов
	static void clearArray();											//Метод отчистки массива
	static void delElem(int n);											//Метод удаления объекта из массива по индексу
	static void showSysInfo();											//Метод вывода служебной информации

private:
	static void checkArray();											//закрытый метод проверки на наличие свободных мест в массиве

};

