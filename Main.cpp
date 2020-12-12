#include "Payment.h"
#include "PaymentWorked.h"
#include "PaymentСompany.h"

int main() {
	setlocale(LC_ALL, "Russian");

	PaymentСompany person1("Olegchenko Oleg Olegovich", 300, 2015, 22, "barista", 500, 23);
	person1.calculationSalary();
	person1.calculationPensionContributions();
	person1.calculationIncomeTax();

	PaymentСompany person2;
	person2 = person1;
	person2.calculationSalary();
	person2.calculationPensionContributions();
	person2.calculationIncomeTax();

	cout << person1 << endl;
	cout << person2 << endl;
	
	PaymentWorked person3("Olegchenko Oleg Olegovich", 300, 2015, 22, "barista", 500);
	person1.calculationSalary();
	person1.calculationPensionContributions();
	person1.calculationIncomeTax();

	PaymentWorked person4;
	person4 = person3;
	person2.calculationSalary();
	person2.calculationPensionContributions();
	person2.calculationIncomeTax();

	cout << person3 << endl;
	cout << person4 << endl;

	allTests();

	cin.get();
    cin.get();
}
