#pragma once
class AbstrBook					//����������� ����� �����
{
public:
	virtual void printBook() const = 0;	//����������� ����� ������ �� ����� �����
	virtual void inputBook() = 0;	//����������� ����� ����� �����
};

