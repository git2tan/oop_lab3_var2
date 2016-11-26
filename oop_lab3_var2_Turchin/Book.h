#pragma once
#include "AbstrBook.h"
#include <string>

class Book :
	public AbstrBook
{
public:
	Book();
	~Book();
private:
	std::string Title;
	std::string Author;
	bool inLib;
};

