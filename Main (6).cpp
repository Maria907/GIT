#include "Payment.h"

int main() {
	setlocale(LC_ALL, "Russian");

	Payment oleg; // Создания объекта "oleg" используя конструктор по умолчанию

	Payment anton ("Антоничевский Антон Антонович", 450, 2014, 22); // Создания объекта "anton" используя конструктор с параметрами

	Payment anton2(anton); // Создания объекта "anton2" используя конструктор копирования

	Payment anton3(anton); // Создания объекта "anton2" используя конструктор копирования

	oleg.calculationSalary();
	oleg.calculationPensionContributions();
	oleg.calculationIncomeTax();
	cout << toString(oleg);
	cout << oleg();
	cout << endl;

	anton.calculationSalary();
	anton.calculationPensionContributions();
	anton.calculationIncomeTax();
	cout << toString(anton);
	cout << anton();
	cout << endl;

	anton2++;
	anton2++;
	anton2--;
	anton2 - 400;
	anton2 + 36;
	anton2.calculationSalary();
	anton2.calculationPensionContributions();
	anton2.calculationIncomeTax();
	cout << toString(anton2);
	cout << anton2();
	cout << endl;

	anton3 = anton;
	cout << toString(anton3);
	cout << anton3();
	cout << endl;

	allTests();

	cin.get();
	cin.get();
}
