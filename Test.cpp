#include "Payment.h"

void testSalary () {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test.calculationSalary();
	assert(test.getSalary() == test.getDailySalary() * test.getWorkedDays());
}

void testPensionContributions () {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test.calculationSalary();
	test.calculationPensionContributions();
	assert(test.getPensionContributions() == test.getSalary() * 0.01);
}

void testIncomeTax () {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test.calculationSalary();
	test.calculationIncomeTax();
	assert(test.getIncomeTax() == test.getSalary() * 0.13);
}

void testToString() {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test.calculationSalary();
	test.calculationIncomeTax();
	test.calculationPensionContributions();
	assert(strcmp(test.toString(),"Данные сотрудника: 'Тестевский Тест Тестович' \n Оклад: 5 р. \n Год поступления на работу: 1 \n Кол-во отработанных дней в месяце: 10 \n Зарплата: 50,00 р. \n Отчисления в пенсионный фонд: 0,50 р. \n Подоходный налог: 6,50 р. \n") == 0);
}

void allTests() {
	testSalary();
	testPensionContributions();
	testIncomeTax();
	testToString();
}