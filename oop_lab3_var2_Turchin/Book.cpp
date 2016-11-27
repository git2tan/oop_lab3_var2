#include "Book.h"

AbstrBook** Book::Array = NULL;
int Book::arraySize = 0;
int Book::objCount = 0;

Book::Book() :Title("<empty>"+ std::to_string(objCount)), Author("<empty>"+ std::to_string(objCount)), inLib(false)
{
	checkArray();						//��������� ������ ������� ��� ��������� �� �������
	Array[objCount++] = this;			//��������� ��������� �� ������ ��� ��������� ������, � ������ ����������
	std::cout << "����������� ��� " << std::endl;
	this->printBook();
}
//Book::Book(std::string Title, std::string Author, bool inLib) : Title(Title), Author(Author), inLib(inLib)
//{
//	checkArray();						//��������� ������ ������� ��� ��������� �� �������
//	Array[objCount++] = this;			////��������� ��������� �� ������ ��� ��������� ������, � ������ ����������
//}
Book::~Book()
{
	this->Title.clear();
	this->Author.clear();
	for (int i = 0; i < objCount; i++)
	{
		if (Array[i] == this)
		{
			if ((objCount > 1) && (i != (objCount-1)))	//������� �� ������������ ������� � �� ���������
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
	std::cout << std::setw(20) << std::left << this->Title
		<< std::setw(20) << std::left << this->Author
		<< (inLib ? "YES" : "NO") << std::endl;
}

Book &Book::setBook(std::string Title, std::string Author, bool inLib)
{
	this->Title = Title;
	this->Author = Author;
	this->inLib = inLib;
	return *this;
}

Book &Book::setInLib(bool inLib)
{
	this->inLib = inLib;
	return *this;
}
Book &Book::setTitle(std::string Title)
{
	if (!Title.empty())
		this->Title = Title;
	else
		this->Title = "<empty(default)>";
	return *this;
}
Book &Book::setAuthor(std::string Author)
{
	if (!Author.empty())
		this->Author = Author;
	else
		this->Author = "<no name>";
	return *this;
}

const bool Book::getInLib() const
{
	return this->inLib;
}
const std::string Book::getTitle() const
{
	return this->Title;
}
const std::string Book::getAuthor() const
{
	return this->Author;
}

void Book::showArray()
{
	std::cout << "ArraySize = " << arraySize << ";   objCount = " << objCount << std::endl;
	if (objCount > 0)
	{
		for (int i = 0; i < objCount; i++)
		{
			Array[i]->printBook();
		}
	}
	else
	{
		std::cout << "Array is empty..." << std::endl;
	}
}

void Book::clearArray()
{
	while (objCount != 0)
		delete (Book*)(Array[0]);
}

void Book::delElem(int n)
{
	if (n >= 0 && n < objCount)
		delete (Book*)(Array[n]);
}

void Book::checkArray()
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
			//������� ������� ������ ��� ��� �����
			AbstrBook ** newArray = new AbstrBook*[arraySize * 2];
			//������������ ���������� ������ � �����
			for (int i = 0; i < arraySize; i++)
			{
				newArray[i] = Array[i];
			}
			delete[] Array;
			Array = newArray;
			arraySize *= 2;
		}
	}
}
