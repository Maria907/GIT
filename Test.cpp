#include "Payment.h"

int main() {
	setlocale(0, "rus");

	Payment person;

	person.setDailySalary(5);
	person.setWorkedDays(10);

	person.calculationSalary();
	assert(person.getSalary() == person.getDailySalary() * person.getWorkedDays());  // Тест функции отвечающей за расчет зарплаты работника пройден

	person.calculationPensionContributions();
	assert(person.getPensionContributions() == person.getSalary() * 0.01);  // Тест функции отвечающей за расчет пенсионных вычетов работника пройден

	person.calculationIncomeTax();
	assert(person.getIncomeTax() == person.getSalary() * 0.13);  // Тест функции отвечающей за расчет подоходного налога работ пройден

	cout << "Все тесты пройдены успешно";

	cin.get();
	cin.get();
}
