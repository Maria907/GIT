#include "Payment.h"

int main() {
	setlocale(LC_ALL, "Russian");

	Payment oleg; // Создания объекта "oleg" используя конструктор по умолчанию

	Payment anton ("Антоничевский Антон Антонович", 450, 2014, 22); // Создания объекта "anton" используя конструктор с параметрами

	Payment anton2(anton); // Создания объекта "anton2" используя конструктор копирования

	oleg.calculationSalary();
	oleg.calculationPensionContributions();
	oleg.calculationIncomeTax();
	cout << oleg.toString();
	cout << endl;

	anton.calculationSalary();
	anton.calculationPensionContributions();
	anton.calculationIncomeTax();
	cout << anton.toString();
	cout << endl;

	anton2.calculationSalary();
	anton2.calculationPensionContributions();
	anton2.calculationIncomeTax();
	cout << anton2.toString();
	cout << endl;

	allTests();

	cin.get();
	cin.get();
}
