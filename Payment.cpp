﻿#include "Payment.h"

Payment::Payment () {
	name = (char*)malloc(24);
	strcpy(name, " ");
	dailySalary = 0;
	employmentYear = 0;
	workedDays = 0;
	counter++;
} // Конструктор по умолчанию

Payment::Payment (const char* valueName, int valueDailySalary, int valueEmploymentYear, int valueWorkedDays) {
	name = (char*)malloc(strlen(valueName));
	strcpy(name, valueName);
	dailySalary = valueDailySalary;
	employmentYear = valueEmploymentYear;
	workedDays = valueWorkedDays;
	counter++;
} // Конструктор с параметрами

Payment::Payment (const Payment& person) {
	name = (char*)malloc(strlen(person.name));
	strcpy(name, person.name);
	dailySalary = person.dailySalary;
	employmentYear = person.employmentYear;
	workedDays = person.workedDays;
	counter++;
} // Конструктор копирования 

char* Payment::getName() {
	return(Payment::name);
} // Геттер для переменной "name"

int Payment::getDailySalary () {
	return(dailySalary);
} // Геттер для переменной "salary"

int Payment::getEmploymentYear () {
	return(employmentYear);
} // Геттер для переменной "employmentYear"

int Payment::getWorkedDays () {
	return(workedDays);
} // Геттер для переменной "workedDays"

float Payment::getSalary () {
	return(salary);
} // Геттер для переменной "salary"

float Payment::getPensionContributions () {
	return(pensionContributions);
} // Геттер для переменной "pensionContributions"

float Payment::getIncomeTax () {
	return(incomeTax);
} // Геттер для переменной "incomeTax"

void Payment::setName(const char* valueName) {
	name = (char*)malloc(strlen(valueName));
	strcpy(name, valueName);
} // Сеттер для переменной "name"

void Payment::setDailySalary(int valueDailySalary) {
	dailySalary = valueDailySalary;
} // Сеттер для переменной "dailySalary"

void Payment::setEmploymentYear(int valueEmploymentYear) {
	employmentYear = valueEmploymentYear;
} // Сеттер для переменной "employmentYear"

void Payment::setWorkedDays(int valueWorkedDays) {
	workedDays = valueWorkedDays;
} // Сеттер для переменной "workedDays"

void Payment::setSalary(float valueSalary) {
	salary = valueSalary;
} // Сеттер для переменной "salary"

void Payment::setPensionContributions(float valuePensionContributions) {
	pensionContributions = valuePensionContributions;
} // Сеттер для переменной "pensionContributions"

void Payment::setIncomeTax(float valueIncomeTax) {
	incomeTax = valueIncomeTax;
} // Сеттер для переменной "incomeTax"

void Payment::calculationSalary() {
	salary = workedDays * dailySalary;
} // Функция класса Payment отвечающая за расчет зарплаты работника 

void Payment::calculationPensionContributions() {
	pensionContributions = salary * 0.01;
} // Функция класса Payment отвечающая за расчет пенсионных вычетов работника 

void Payment::calculationIncomeTax() {
	incomeTax = salary * 0.13;
} // Функция класса Payment отвечающая за расчет подоходного налога работника 

char* Payment::toString() {
	char* stringObj = (char*)malloc(strlen(name) + 10000);
	sprintf(stringObj, "Данные сотрудника: '%s' \n Оклад: %d р. \n Год поступления на работу: %d \n Кол-во отработанных дней в месяце: %d \n Зарплата: %.2f р. \n Отчисления в пенсионный фонд: %.2f р. \n Подоходный налог: %.2f р. \n", name, dailySalary, employmentYear, workedDays, salary, pensionContributions, incomeTax);
	return (stringObj);
} // Функция класса Payment отвечающая за строковое представление объекта

int Payment::counter = 0; // Инициализация статического члена класса 
