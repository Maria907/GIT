#include "Payment.h"

Payment::Payment () {
	FIO = (char*)malloc(24);
	strcpy(FIO, "Олегченко Олег Олегович");
	dailySalary = 500;
	employmentYear = 2012;
	workedDays = 22;
	counter++;
} // Конструктор по умолчанию

Payment::Payment (const char* valueFIO, int valueDailySalary, int valueEmploymentYear, int valueWorkedDays) {
	FIO = (char*)malloc(strlen(valueFIO));
	strcpy(FIO, valueFIO);
	dailySalary = valueDailySalary;
	employmentYear = valueEmploymentYear;
	workedDays = valueWorkedDays;
	counter++;
} // Конструктор с параметрами

Payment::Payment (const Payment& name) {
	FIO = (char*)malloc(strlen(name.FIO));
	strcpy(FIO, name.FIO);
	dailySalary = name.dailySalary;
	employmentYear = name.employmentYear;
	workedDays = name.workedDays;
	counter++;
} // Конструктор копирования 

char* Payment::getFIO () {
	return(Payment::FIO);
} // Геттер для переменной "FIO"

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

void Payment::setFIO(const char* valueFIO) {
	FIO = (char*)malloc(strlen(valueFIO));
	strcpy(FIO, valueFIO);
} // Сеттер для переменной "FIO"

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

char* Payment::to_string() {
	char* stringObj = (char*)malloc(strlen(FIO) + 10000);
	sprintf(stringObj, "Данные сотрудника: '%s' \n Оклад: %d р. \n Год поступления на работу: %d \n Кол-во отработанных дней в месяце: %d \n Зарплата: %.2f р. \n Отчисления в пенсионный фонд: %.2f р. \n Подоходный налог: %.2f р. \n", FIO, dailySalary, employmentYear, workedDays, salary, pensionContributions, incomeTax);
	return (stringObj);
} // Функция класса Payment отвечающая за строковое представление объекта

int Payment::counter = 0; // Инициализация статического члена класса 
