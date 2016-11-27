#include "Book.h"

void menu();

///////////////////////////////////////////////////////////////////////////////////////

void main()
{
	setlocale(LC_ALL, "Russian");
	menu();
}

//////////////////////////////////////////////////////////////////////////////////////

void menu()
{
	char c = 0;
	int t;
	while (c != '0')
	{
		std::cout << "Меню:" << std::endl;
		std::cout << "1. Добавить объект" << std::endl;
		std::cout << "2. Удалить объект" << std::endl;
		std::cout << "3. Вывести массив объектов на экран" << std::endl;
		std::cout << "4. Очистить массив" << std::endl;
		std::cout << "0. Выход" << std::endl;
		std::cin >> c;
		switch (c)
		{
		case '1':
			new Book();
			break;
		case '2':
			std::cout << "Введите номер удаляемого: " << std::endl;
			std::cin >> t;
			Book::delElem(t);
			break;
		case '3':
			Book::showArray();
			system("pause");
			break;
		case '4':
			Book::clearArray();
			break;
		case '0':
			Book::clearArray();
			break;
		default:
			std::cout << "Fail" << std::endl;
			break;
		}
	}
}