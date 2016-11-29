#include "Book.h"

AbstrBook** Book::Array = NULL;			//�������������� ����������� ����������
int Book::arraySize = 0;				//
int Book::objCount = 0;					//

Book::Book() :Title("<empty>"+ std::to_string(objCount)), Author("<empty>"+ std::to_string(objCount)), inLib(false)
{
	checkArray();						//��������� ������ ������� ��� ��������� �� �������
	Array[objCount++] = this;			//��������� ��������� �� ������ ��� ��������� ������, � ������ ����������
	std::cout << "����������� ��� :" << std::endl;	//������� ��������� � ��� ��� ��� ������� ���� �������
	this->printBook();
}

Book::~Book()
{
	this->Title.clear();								//������� � �������� �������� ���� Title
	this->Author.clear();								//������� ���� Author
	for (int i = 0; i < objCount; i++)					//�������� �� ������� � ����� ������ ���������� �������� (��������) this
	{
		if (Array[i] == this)							//������� ���������� ������������ ��������
		{
			if ((objCount > 1) && (i != (objCount-1)))	//���� ������� �� ������������ ������� � �� ���������
			{
				Array[i] = Array[objCount - 1];			//�������� ��������� ��������� �� ��������� � �������
				objCount--;								//��������� ������� ��������
			}
			else 
			{
				objCount--;								//����� ������ ��������� ������� ���������� ���������
			}
		}
	}
	if (objCount == 0)									//���� ������� ��� ��������
	{
		delete[]Array;									//������� ������ �� ��� ������� ����������
		Array = NULL;									//������������� ��������� �� ������ ��� NULL
		arraySize = 0;									//������������� ������ �������� ������� � 0
	}
	else if (objCount <= (arraySize / 2 - arraySize / 2 / 4))		//�������� ���������� ������� ������� ��� ���������� ����������� �������
	{
		AbstrBook** newArray = new AbstrBook*[arraySize/2];			//�������� ������ ��� ������ � 2 ���� ������� ��� �������
		for (int i = 0; i < objCount; i++)							//������������ ��� �� �������� � ������ ��� ���������
		{
			newArray[i] = Array[i];
		}
		delete[]Array;												//����������� ������ �� ��� ��������
		Array = newArray;											//������������� ������� ��������� �����
		arraySize /= 2;												//�������� � ������������ ������ �������� �������
	}
}

void Book::printBook() const										//����������� ����� ������ ������� �� �����
{
	std::cout << std::setw(20) << std::left << this->Title			//������������� ������ ������ ��������� ������������ ������ � ������� ������
		<< std::setw(20) << std::left << this->Author
		<< (inLib ? "YES" : "NO") << std::endl;
}

void Book::input()								//����� �������� �������� �������� �� ��������� �� ��������� � ����������
{
	std::cout << "Please, input the new Title" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::string s1;														
	std::getline(std::cin, s1);											//��������� ������
	if (!s1.empty())													//���� ��������� ������ �� ������
		this->Title = s1;												//������������� �������� Title �� ��� ���� ������� � ����������
	else
		this->Title = "<empty(default)>" + std::to_string(objCount);	//� ���� �����, �� ��������� ��������� �� ���������

	std::cout << "Please, input the new Author" << std::endl;			//������ ���������� ��� ���� Author
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::string s2;														
	std::getline(std::cin, s2);
	if (!s2.empty())
		this->Author = s2;
	else
		this->Author = "<no name>" + std::to_string(objCount);

	std::cout << "Is book in the Library? Yes(1) or no(0)" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	int tmp;
	std::cin >> tmp;
	while (true)														//������� �� ����� �������� ���������� ����� �� ������ (���������� ��� 1(��) ���  0(���)
	{
		if (tmp == 1)									
		{
			inLib = true;
			break;
		}
		if (tmp == 0)
		{
			inLib = false;
			break;
		}
		//���� ����� �� ����� ����� - ������ ������������ ���� ������������ ������
		std::cout << "Sorry, uncorect input. Try again! Is book in Library? Yes(1) or no(0)" << std::endl;
		std::cout << ">>>";
		std::cin.ignore(std::cin.rdbuf()->in_avail());					//����������� �����.
		std::cin >> tmp;												//��������� ����� �������
	}
}

void Book::showArray()												//����������� ����� ������ ������� �������� �� �����
{
	std::cout << "ArraySize = " << arraySize << ";   objCount = " << objCount << std::endl;
	if (objCount > 0)												//���� ���������� �������� ������ 0
	{
		for (int i = 0; i < objCount; i++)							//��������� ������ �� �������
		{
			Array[i]->printBook();									//�������� ����� ������ �� ����� ������� �������
		}
	}
	else
	{
		std::cout << "Array is empty..." << std::endl;				//����� ������� ��������� ��� ������ ����
	}
}

void Book::clearArray()												//������� ������
{
	while (objCount != 0)											//
	{
		delete (Book*)(Array[0]);									//������� ������� ������� �.�.�� ��������� ������ ����������� ��������� ���� � ������ �������
	}									 
}																	//�.�.�������� �������� ��������

void Book::delElem(int n)											//����������� ����� �������� �� �������
{
	if (n >= 0 && n < objCount)										//���� ������������ ������ ����������
		delete (Book*)(Array[n]);									//�������� ���������� ������ Book, ��� ����� ��������� ����������� ��� ��������� � ������� ��������� �� ������-���������
}

void Book::showSysInfo()
{
	std::cout << "arraySize: " << arraySize << ";   objCount: " << objCount << std::endl;	//������� ��������� ���������� � �������
}

void Book::createAndInputNewObj()
{
	Book *newBook = new Book();				//������� ��������� � ������� ������ �� ����� ���������
	newBook->input();						//������ �������� ����� � ���������� ������� �� �������� ��������� � ����������
}

void Book::checkArray()						//�������� ����� �������� �� ������� ��������� ���� � �������
{
	if (Array==NULL)						//���� ������ �� ��� ������������������ �� ������� ����� ������ �� 2 ��������
	{
		Array = new AbstrBook*[2];			//�������� ������ ��� ��� ������
		arraySize = 2;						//�������� ����������-������ �������
	}
	else
	{
		if (arraySize < (objCount + 1))		//���� ������ ������� �� ��������� �������� ��� ���� ������ (��������)
		{
			//������� ������� ������ ��� �������
			AbstrBook ** newArray = new AbstrBook*[arraySize * 2];
			
			//������������ ������� ������ � �����
			for (int i = 0; i < arraySize; i++)
			{
				newArray[i] = Array[i];
			}
			delete[] Array;					//����������� ������ �� ��� �������� ������� ����������
			Array = newArray;				//������������� ������� ������ ��� ���������
			arraySize *= 2;					//�������� � ������������ ������ �������
		}
	}
}
