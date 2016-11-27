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
