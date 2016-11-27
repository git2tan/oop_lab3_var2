#pragma once
#include "AbstrBook.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

class Book :
	public AbstrBook													//��������� �� ������������ ������ (�� ����������?)
{
private:
	std::string Title;													//�������� �����
	std::string Author;													//�����
	bool inLib;															//������� � ���������� (�� ��� ���)

	static AbstrBook** Array;											//������ ���������� �� ������� ������������� ������
	static int objCount;												//���������� ��������������������� ��������
	static int arraySize;												//������ ������� ��� �������� ����������
public:
	Book();																//����������� �� ���������
	//Book(std::string, std::string, bool);								//����������� � �����������

	~Book();															//����������

	virtual void printBook() const;										//���������� ������ ������ �� ����� �� ������������ ������
	
	static void showArray();											//����� ������ �� ����� ����� ������� ��������
	static void clearArray();											//����� �������� �������
	static void delElem(int n);											//����� �������� ������� �� ������� �� �������
	static void showSysInfo();											//����� ������ ��������� ����������

private:
	static void checkArray();											//�������� ����� �������� �� ������� ��������� ���� � �������

};

