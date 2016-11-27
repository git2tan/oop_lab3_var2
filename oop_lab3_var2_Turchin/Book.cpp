#include "Book.h"

AbstrBook** Book::Array = NULL;
int Book::arraySize = 0;
int Book::objCount = 0;

Book::Book() :Title("<empty>"+ std::to_string(objCount)), Author("<empty>"+ std::to_string(objCount)), inLib(false)
{
	checkArray();						//проверяем размер массива под указатели на объекты
	Array[objCount++] = this;			//вставляем указатель на только что созданный объект, в массив указателей
	std::cout << "Конструктор для " << std::endl;
	this->printBook();
}
//Book::Book(std::string Title, std::string Author, bool inLib) : Title(Title), Author(Author), inLib(inLib)
//{
//	checkArray();						//проверяем размер массива под указатели на объекты
//	Array[objCount++] = this;			////вставляем указатель на только что созданный объект, в массив указателей
//}
Book::~Book()
{
	this->Title.clear();
	this->Author.clear();
	for (int i = 0; i < objCount; i++)
	{
		if (Array[i] == this)
		{
			if ((objCount > 1) && (i != (objCount-1)))	//Удаляем не единственный элемент и не последний
			{
				Array[i] = Array[objCount - 1];			//Заменяем удаляемый указатель на последний в массиве
				objCount--;								//уменьшаем счетчик объектов
			}
			else 
			{
				objCount--;								//иначе просто уменьшаем счетчик количества элементов
			}
		}
	}
	if (objCount == 0)									//если удалили все элементы
	{
		delete[]Array;									//удаляем память из под массива указателей
		Array = NULL;									//Устанавливаем указатель на массив как NULL
		arraySize = 0;									//Устанавливаем размер текущего массива в 0
	}
	else if (objCount <= (arraySize / 2 - arraySize / 2 / 4))		//Алгоритм уменьшения размера массива при достижении необходимых условий
	{
		AbstrBook** newArray = new AbstrBook*[arraySize/2];			//Выделяем память под массив в 2 раза меньший чем текущий
		for (int i = 0; i < objCount; i++)							//Переписываем все из текущего в только что созданный
		{
			newArray[i] = Array[i];
		}
		delete[]Array;												//Освобождаем память из под текущего
		Array = newArray;											//Устанавливаем текущим созданный ранее
		arraySize /= 2;												//Приводим в соответствие размер текущего массива
	}
}

void Book::printBook() const										//Статический метод вывода объекта на экран
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
	if (Array==NULL)						//если массив не был проинициализирован то создаем новый массив на 2 элемента
	{
		Array = new AbstrBook*[2];			//выделяем память под сам массив
		arraySize = 2;						//изменяем переменную-размер массива
	}
	else
	{
		if (arraySize < (objCount + 1))		//если размер массива не позволяет дописать еще один объект (заполнен)
		{
			//создаем больший массив чем был ранее
			AbstrBook ** newArray = new AbstrBook*[arraySize * 2];
			//переписываем предыдущий массив в новый
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
