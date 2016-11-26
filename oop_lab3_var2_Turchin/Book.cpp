#include "Book.h"


Book::Book() :Title("<empty>"), Author("<empty>"), inLib(false)
{
}

Book::Book(std::string Title, std::string Author, bool inLib) : Title(Title), Author(Author), inLib(inLib)
{
}

Book::~Book()
{
}

void Book::printBook() const
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