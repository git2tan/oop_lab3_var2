#include "Book.h"

AbstrBook** Book::Array = NULL;
int Book::arraySize = 0;
int Book::objCount = 0;

Book::Book() :Title("<empty>"+ std::to_string(objCount)), Author("<empty>"+ std::to_string(objCount)), inLib(false)
{
	checkArray();						//проверяем размер массива под указатели на объекты
	Array[objCount++] = this;			//вставляем указатель на только что созданный объект, в массив указателей
	std::cout << "Конструктор для :" << std::endl;
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

void Book::input()								//метод заменяет значения заданные по умолчанию на введенные с клавиатуры
{
	std::cout << "Please, input the new Title" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::string s1;
	std::getline(std::cin, s1);
	if (!s1.empty())
		this->Title = s1;
	else
		this->Title = "<empty(default)>" + std::to_string(objCount);

	std::cout << "Please, input the new Author" << std::endl;
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
	while (true)
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
		std::cout << "Sorry, uncorect input. Try again! Is book in Library? Yes(1) or no(0)" << std::endl;
		std::cout << ">>>";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> tmp;
	}
}

void Book::showArray()												//Статический метод вывода массива объектов на экран
{
	std::cout << "ArraySize = " << arraySize << ";   objCount = " << objCount << std::endl;
	if (objCount > 0)												//Если количество объектов больше 0
	{
		for (int i = 0; i < objCount; i++)							//пробегаем циклом по массиву
		{
			Array[i]->printBook();									//вызываем метод вывода на экран каждому объекту
		}
	}
	else
	{
		std::cout << "Array is empty..." << std::endl;				//иначе выводим сообщение что массив пуст
	}
}

void Book::clearArray()												//Очищаем массив
{
	while (objCount != 0)											//
		delete (Book*)(Array[0]);									//Удаляем нулевой элемент т.к.по алгоритму внутри деструктора сравнение идет с начала массива 
}																	//т.о.ускаряем алгоритм удаления

void Book::delElem(int n)											//Статический метод удаления по индексу
{
	if (n >= 0 && n < objCount)										//Если передаваемый индекс корректный
		delete (Book*)(Array[n]);									//Вызываем деструктор класса Book, для этого указываем компилятору что указатели в массиве указывают на объект-наследник
}

void Book::showSysInfo()
{
	std::cout << "arraySize: " << arraySize << ";   objCount: " << objCount << std::endl;
}

void Book::createAndInputNewObj()
{
	Book *newBook = new Book();
	newBook->input();
}

void Book::checkArray()						//Закрытый метод проверки на наличие свободных мест в массиве
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
			//создаем больший массив чем текущий
			AbstrBook ** newArray = new AbstrBook*[arraySize * 2];
			//переписываем текущий массив в новый
			for (int i = 0; i < arraySize; i++)
			{
				newArray[i] = Array[i];
			}
			delete[] Array;					//Освобождаем память из под текущего массива указателей
			Array = newArray;				//Устанавливаем текущим только что созданный
			arraySize *= 2;					//Приводим в соответствие размер массива
		}
	}
}
