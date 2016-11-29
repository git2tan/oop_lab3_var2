#include "Book.h"

void menu();		//������� ������ ����
enum MyEnum			//�������������
{
	exit0, add, del, show, clear, input			//������� ���������� ��� ������� ������� ����
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
		Book::showSysInfo();												//����� ��������� ����������
		std::cout << "����:" << std::endl;
		std::cout << add << ". �������� ������" << std::endl;
		std::cout << del << ". ������� ������" << std::endl;
		std::cout << show << ". ������� ������ �������� �� �����" << std::endl;
		std::cout << clear << ". �������� ������" << std::endl;
		std::cout << input << ". ������ ����� ������" << std::endl;
		std::cout << "0. �����" << std::endl;
		
		std::cin >> c;
		switch (c)
		{
		case (add):
			new Book();
			break;
		case (del):
			std::cout << "������� ����� ����������: " << std::endl;
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