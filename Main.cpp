#include "Payment.h"

int main() {
	setlocale(LC_ALL, "Russian");

	Payment oleg; // Создания объекта "oleg" используя конструктор по умолчанию

	Payment anton ("Антоничевский Антон Антонович", 450, 2014, 22); // Создания объекта "anton" используя конструктор с параметрами

	Payment anton2(anton); // Создания объекта "anton2" используя конструктор копирования

	oleg.calculationSalary();
	oleg.calculationPensionContributions();
	oleg.calculationIncomeTax();
	cout << oleg.to_string();
	cout << endl;

	anton.calculationSalary();
	anton.calculationPensionContributions();
	anton.calculationIncomeTax();
	cout << anton.to_string();
	cout << endl;

	anton2.calculationSalary();
	anton2.calculationPensionContributions();
	anton2.calculationIncomeTax();
	cout << anton2.to_string();
	cout << endl;

	oleg.testSalary();  // Тест функции отвечающей за расчет зарплаты работника пройден
	oleg.testPensionContributions(); // Тест функции отвечающей за расчет пенсионных вычетов работника пройден
	oleg.testIncomeTax();  // Тест функции отвечающей за расчет подоходного налога работ пройден

	cin.get();
	cin.get();
}
