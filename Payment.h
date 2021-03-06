﻿#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <assert.h>
#include <fstream>
#include "Test.h"
using namespace std;

class Payment {
public:
	Payment(); // Объявление конструктора по умолчанию
	Payment(const char* valueName, int valueDailySalary, int valueEmploymentYear, int valueWorkedDays); // Объявление конструктора с параметрами
	Payment(const Payment& person); // Объявление конструктора копирования 
	~Payment();

	void calculationSalary (); // Объявление функции отвечающей за расчет зарплаты работника
	void calculationPensionContributions (); // Объявление функции отвечающей за расчет пенсионных вычетов работника
	void calculationIncomeTax (); // Объявление функции отвечающей за расчет подоходного налога работника

	char* toString(); // Объявление функции отвечающей за строковое представление объекта

	char* getName(); // Объявление геттера для переменной "name"
	int getDailySalary (); // Объявление геттера для переменной "dailySalary"
	int getEmploymentYear (); // Объявление геттера для переменной "employmentYear"
	int getWorkedDays (); // Объявление геттера для переменной "workedDays"
	float getSalary (); // Объявление геттера для переменной "salary"
	float getPensionContributions (); // Объявление геттера для переменной "pensionContributions"
	float getIncomeTax (); // Объявление геттера для переменной "incomeTax"

	void setName(const char* valueName); // Объявление сеттера для переменной "name"
	void setDailySalary (int valueDailySalary); // Объявление сеттера для переменной "dailySalary"
	void setEmploymentYear (int valueEmploymentYear); // Объявление сеттера для переменной "employmentYear"
	void setWorkedDays (int valueWorkedDays); // Объявление сеттера для переменной "workedDays"
	void setSalary (float valueSalary); // Объявление сеттера для переменной "salary"
	void setPensionContributions (float valuePensionContributions); // Объявление сеттера для переменной "pensionContributions"
	void setIncomeTax (float valueIncomeTax); // Объявление сеттера для переменной "incomeTax"

	Payment& operator - (int b);
	Payment& operator + (int b);
	Payment& operator -- (int);
	Payment& operator ++ (int);
	Payment& operator -- ();
	Payment& operator ++ ();

	friend bool operator == (Payment& person1, Payment& person2);
	friend bool operator != (Payment& person1, Payment& person2);

	Payment operator = (const Payment& person);

	char* operator() ();

	static int counter; // Объявление статического члена класса - счетчика 

	friend ostream& operator << (ostream& out, const Payment& person);
	friend istream& operator >> (istream& in, Payment& person);

	friend ofstream& operator << (ofstream& out, const Payment& person);

	void binarySave(ofstream& save);
	void binaryLoad(ifstream& load);

protected:
	char* name; // Объявление переменной, содержащей ФИО работника
	int dailySalary; // Объявление переменной, содержащей оклад работника
	int employmentYear; // Объявление переменной, содержащей год принятия работника 
	int workedDays; // Объявление переменной, содержащей отработанные работником дни за месяц 
	float salary; //Объявление переменной, содержащей зарплату работника
	float pensionContributions; // Объявление переменной, содержащей пенсионный вычет работника
	float incomeTax; // Объявление переменной, содержащей подоходный налог работника
}; // Объявление класса Payment
