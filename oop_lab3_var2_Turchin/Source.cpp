#include "Book.h"

void menu();		//Функция вывода меню
enum MyEnum			//перечислитель
{
	exit0, add, del, show, clear, input			//Заводим переменные для номеров пунктов меню
};
///////////////////////////////////////////////////////////////////////////////////////

void main()
{
	setlocale(LC_ALL, "Russian");
	menu();
}

//////////////////////////////////////////////////////////////////////////////////////

void menu()
{
	int c=1;
	int t;
	while (c != exit0)
	{
		std::cout << std::setw(56) << std::setfill('+') << "+" << std::setfill(' ') << std::endl;
		Book::showSysInfo();												//Вывод служебной информации
		std::cout << "Меню:" << std::endl;
		std::cout << add << ". Добавить объект" << std::endl;
		std::cout << del << ". Удалить объект" << std::endl;
		std::cout << show << ". Вывести массив объектов на экран" << std::endl;
		std::cout << clear << ". Очистить массив" << std::endl;
		std::cout << input << ". Ввести новый объект" << std::endl;
		std::cout << "0. Выход" << std::endl;
		
		std::cin >> c;
		switch (c)
		{
		case (add):
			new Book();
			break;
		case (del):
			std::cout << "Введите номер удаляемого: " << std::endl;
			std::cin >> t;
			Book::delElem(t);
			break;
		case (show):
			Book::showArray();
			system(
				"pause");
			break;
		case (clear):
			Book::clearArray();
			break;
		case (exit0):
			Book::clearArray();
			break;
		case (input):
			Book::createAndInputNewObj();
			break;
		default:
			std::cout << "Fail" << std::endl;
			break;
		}
	}
}