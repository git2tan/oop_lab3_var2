#pragma once
#include "AbstrBook.h"		//���������� ����� - ��������
#include <iostream>			//���������� ���������� i/o  �������
#include <iomanip>			//���������� ���������� ��� �������������� ������
#include <string>			//���������� ����������� ������������ ����� ��� ������������� ��� � �������� ����� ������

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
	~Book();															//����������

	virtual void printBook() const;										//���������� ������ ������ �� ����� �� ������������ ������
	virtual void input();												//���������� ������ ����� �������
	static void showArray();											//����� ������ �� ����� ����� ������� ��������
	static void clearArray();											//����� �������� �������
	static void delElem(int n);											//����� �������� ������� �� ������� �� �������
	static void showSysInfo();											//����� ������ ��������� ����������
	static void createAndInputNewObj();									//����� ����������� ���� ������ ��������
private:
	static void checkArray();											//�������� ����� �������� �� ������� ��������� ���� � �������

};

