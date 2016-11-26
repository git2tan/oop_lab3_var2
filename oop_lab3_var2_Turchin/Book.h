#pragma once
#include "AbstrBook.h"
#include <iostream>
#include <iomanip>
#include <string>

class Book :
	public AbstrBook
{
public:
	Book();
	Book(std::string, std::string, bool);

	~Book();

	void printBook() const;
	void inputBook();
	
	Book &setBook(std::string Title, std::string Author, bool inLib);
	Book &setInLib(bool inLib);
	Book &setTitle(std::string);
	Book &setAuthor(std::string);

	const bool getInLib() const;
	const std::string getTitle() const;
	const std::string getAuthor() const;
		
private:
	std::string Title;
	std::string Author;
	bool inLib;
};

