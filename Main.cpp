#include "Payment.h"

int main() {
	setlocale(LC_ALL, "Russian");

	Payment person1("Olegchenko Oleg Olegovich", 300, 2015, 22);
    Payment person2("Poshel naxui", 300, 2015, 22);
    person1.calculationSalary();
    person1.calculationPensionContributions();
    person1.calculationIncomeTax();


    ofstream save("test.txt", ios_base::app);
    if (save.is_open()) {
        save << person1;
        save.close();
    }

    ifstream load("test.txt", ios_base::in);
    if (load.is_open()) {
        load >> person2;
        load.close();
    }

    person2.calculationSalary();
    person2.calculationPensionContributions();
    person2.calculationIncomeTax();
    cout << person2 << endl;

    ofstream saveB("testBinary.txt", ios_base::binary);
    person1.binarySave(saveB);
    saveB.close();

    ifstream loadB("testBinary.txt", ios_base::binary);
    person2.binaryLoad(loadB);
    loadB.close();
    cout << person2 << endl;

    fstream clearFile("test.txt", ios::out);
    clearFile.close();

    fstream clearFileB("testBinary.txt", ios::out);
    clearFileB.close();

	allTests();

	cin.get();
    cin.get();
}
