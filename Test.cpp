#include "Payment.h"

void testSalary() {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test.calculationSalary();
	assert(test.getSalary() == test.getDailySalary() * test.getWorkedDays());
}

void testPensionContributions() {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test.calculationSalary();
	test.calculationPensionContributions();
	assert(test.getPensionContributions() == test.getSalary() * 0.01);
}

void testIncomeTax() {
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
	assert(strcmp(toString(test), "Данные сотрудника: 'Тестевский Тест Тестович' \n Оклад: 5 р. \n Год поступления на работу: 1 \n Кол-во отработанных дней в месяце: 10 \n Зарплата: 50,00 р. \n Отчисления в пенсионный фонд: 0,50 р. \n Подоходный налог: 6,50 р. \n") == 0);
}

void testAddition() {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test + 5;
	assert(test.getDailySalary() == 10);
}

void testSubtraction() {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test - 4;
	assert(test.getDailySalary() == 1);
}

void testIncrement() {
	Payment test("Тестевский Тест Тестович", 5, 1, 10);
	test++;
	assert(test.getEmploymentYear() == 2);

	++test;
	assert(test.getEmploymentYear() == 3);
}
void testDecrement() {
	Payment test("Тестевский Тест Тестович", 5, 3, 10);
	test--;
	assert(test.getEmploymentYear() == 2);

	--test;
	assert(test.getEmploymentYear() == 1);
}

void testFinalSalary() {
	Payment test("Тестевский Тест Тестович", 5, 3, 10);
	test.calculationSalary();
	test.calculationIncomeTax();
	test.calculationPensionContributions();
	assert(strcmp(test(), " Зарплата с вычетом всех процентов: 43,00 р. \n") == 0); // Тест перегруженного оператора <= (случай, когда <)комплексных чисел пройден
}

void testAssignment() {
	Payment test("Тестевский Тест Тестович", 5, 3, 10);
	test.calculationSalary();
	test.calculationIncomeTax();
	test.calculationPensionContributions();
	Payment test2("Тестевский2 Тест2 Тестович2", 23, 643, 65);
	test2.calculationSalary();
	test2.calculationIncomeTax();
	test2.calculationPensionContributions();
	test2 = test;
	assert(test2 == test);

	Payment test3("Тестевский3 Тест3 Тестович3", 64, 123, 87);
	test3.calculationSalary();
	test3.calculationIncomeTax();
	test3.calculationPensionContributions();
	Payment test4("Тестевский4 Тест4 Тестович4", 54, 37, 59);
	test4.calculationSalary();
	test4.calculationIncomeTax();
	test4.calculationPensionContributions();
	test4 = test3 = test;
	assert(test3 == test);
	assert(test4 == test3);

	Payment test5(test);
	test = test;
	assert(test == test5);
}

void allTests() {
	testSalary();
	testPensionContributions();
	testIncomeTax();
	testToString();

	testAddition();
	testSubtraction();
	testIncrement();
	testDecrement();
	testFinalSalary();
	testAssignment();
}