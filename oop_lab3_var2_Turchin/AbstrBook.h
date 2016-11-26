#pragma once
class AbstrBook					//Абстрактный класс Книга
{
public:
	virtual void printBook() const = 0;	//Виртуальный метод вывода на экран книги
	virtual void inputBook() = 0;	//Виртуальный метод ввода книги
};

