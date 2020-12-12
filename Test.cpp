#include "Payment.h"
#include "PaymentWorked.h"
#include "PaymentCompany.h"

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
	assert(strcmp(test.toString(), "Данные сотрудника: 'Тестевский Тест Тестович' \n Оклад: 5 р. \n Год поступления на работу: 1 \n Кол-во отработанных дней в месяце: 10 \n Зарплата: 50,00 р. \n Отчисления в пенсионный фонд: 0,50 р. \n Подоходный налог: 6,50 р. \n") == 0);
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
	assert(strcmp(test(), " Зарплата с вычетом всех процентов: 43,00 р. \n") == 0); 
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


void testSaveLoad() {
	Payment personForSave[5], personForLoad[5];
	ofstream save("test.txt", ios_base::app);

	personForSave[0] = Payment("Teschenko1 Test1 Testovich1", 1, 1, 1);
	personForSave[0].calculationSalary();
	personForSave[0].calculationPensionContributions();
	personForSave[0].calculationIncomeTax();

	personForSave[1] = Payment("Teschenko2 Test2 Testovich2", 2, 2, 2);
	personForSave[1].calculationSalary();
	personForSave[1].calculationPensionContributions();
	personForSave[1].calculationIncomeTax();

	personForSave[2] = Payment("Teschenko3 Test3 Testovich3", 3, 3, 3);
	personForSave[2].calculationSalary();
	personForSave[2].calculationPensionContributions();
	personForSave[2].calculationIncomeTax();

	personForSave[3] = Payment("Teschenko4 Test4 Testovich4", 4, 4, 4);
	personForSave[3].calculationSalary();
	personForSave[3].calculationPensionContributions();
	personForSave[3].calculationIncomeTax();

	personForSave[4] = Payment("Teschenko5 Test5 Testovich5", 5, 5, 5);
	personForSave[4].calculationSalary();
	personForSave[4].calculationPensionContributions();
	personForSave[4].calculationIncomeTax();

	if (save.is_open()) {
		for (int i = 0; i < 5; i++) {
			save << personForSave[i];
		}
		save.close();
	}

	ifstream load("test.txt", ios_base::in);
	if (load.is_open()) {
		for (int i = 0; i < 5; i++) {
			load >> personForLoad[i];
			personForLoad[i].calculationSalary();
			personForLoad[i].calculationPensionContributions();
			personForLoad[i].calculationIncomeTax();
			assert(personForLoad[i] == personForSave[i]);
		}
		load.close();
	}

	fstream clearFile("test.txt", ios::out);
	clearFile.close();
}

void testSaveLoadBinary() {
	Payment personForSave[5], personForLoad[5];
	ofstream saveB("testBinary.txt", ios_base::binary);

	personForSave[0] = Payment("Teschenko1 Test1 Testovich1", 1, 1, 1);
	personForSave[0].calculationSalary();
	personForSave[0].calculationPensionContributions();
	personForSave[0].calculationIncomeTax();

	personForSave[1] = Payment("Teschenko2 Test2 Testovich2", 2, 2, 2);
	personForSave[1].calculationSalary();
	personForSave[1].calculationPensionContributions();
	personForSave[1].calculationIncomeTax();

	personForSave[2] = Payment("Teschenko3 Test3 Testovich3", 3, 3, 3);
	personForSave[2].calculationSalary();
	personForSave[2].calculationPensionContributions();
	personForSave[2].calculationIncomeTax();

	personForSave[3] = Payment("Teschenko4 Test4 Testovich4", 4, 4, 4);
	personForSave[3].calculationSalary();
	personForSave[3].calculationPensionContributions();
	personForSave[3].calculationIncomeTax();

	personForSave[4] = Payment("Teschenko5 Test5 Testovich5", 5, 5, 5);
	personForSave[4].calculationSalary();
	personForSave[4].calculationPensionContributions();
	personForSave[4].calculationIncomeTax();
	
	if (saveB.is_open()) {
		for (int i = 0; i < 5; i++) {
			personForSave[i].binarySave(saveB);
		}
		saveB.close();
	}

	ifstream loadB("testBinary.txt", ios_base::binary);
	if (loadB.is_open()) {
		for (int i = 0; i < 5; i++) {
			personForLoad[i].binaryLoad(loadB);
			assert(personForLoad[i] == personForSave[i]);
		}
		loadB.close();
	}

	fstream clearFileB("testBinary.txt", ios::out);
	clearFileB.close();
}

void testSalaryWorked() {
	PaymentWorked test("Тестевский Тест Тестович", 5, 1, 10, "Тест", 500);
	test.calculationSalary();
	assert(test.getSalary() == (test.getDailySalary() + test.getAllowance()) * test.getWorkedDays());
}

void testToStringyWorked() {
	PaymentWorked test("Тестевский Тест Тестович", 5, 1, 10, "Тест", 500);
	test.calculationSalary();
	test.calculationIncomeTax();
	test.calculationPensionContributions();
	assert(strcmp(test.toString(), "Данные сотрудника: 'Тестевский Тест Тестович' \n Оклад: 5 р. \n Год поступления на работу: 1 \n Кол-во отработанных дней в месяце: 10 \n Зарплата: 5050,00 р. \n Отчисления в пенсионный фонд: 50,50 р. \n Подоходный налог: 656,50 р. \n Должность: 'Тест' \n Надбавка за должность: 500 р. \n") == 0);
}

void testAssignmentyWorked() {
	PaymentWorked test("Тестевский Тест Тестович", 1, 1, 1, "Тест", 1);
	test.calculationSalary();
	test.calculationIncomeTax();
	test.calculationPensionContributions();
	PaymentWorked test2("Тестевский2 Тест2 Тестович2", 2, 2, 2, "Тест2", 2);
	test2.calculationSalary();
	test2.calculationIncomeTax();
	test2.calculationPensionContributions();
	test2 = test;
	assert(test2 == test);

	PaymentWorked test3("Тестевский3 Тест3 Тестович3", 3, 3, 3, "Тест3", 3);
	test3.calculationSalary();
	test3.calculationIncomeTax();
	test3.calculationPensionContributions();
	PaymentWorked test4("Тестевский4 Тест4 Тестович4", 4, 4, 4, "Тест3", 3);
	test4.calculationSalary();
	test4.calculationIncomeTax();
	test4.calculationPensionContributions();
	test4 = test3 = test;
	assert(test3 == test);
	assert(test4 == test3);

	PaymentWorked test5(test);
	test = test;
	assert(test == test5);
}

void testSaveLoadyWorked() {
	PaymentWorked personForSave[5], personForLoad[5];
	ofstream save("test.txt", ios_base::app);

	personForSave[0] = PaymentWorked("Teschenko1 Test1 Testovich1", 1, 1, 1, "Test1", 1);
	personForSave[0].calculationSalary();
	personForSave[0].calculationPensionContributions();
	personForSave[0].calculationIncomeTax();

	personForSave[1] = PaymentWorked("Teschenko2 Test2 Testovich2", 2, 2, 2, "Test2", 2);
	personForSave[1].calculationSalary();
	personForSave[1].calculationPensionContributions();
	personForSave[1].calculationIncomeTax();

	personForSave[2] = PaymentWorked("Teschenko3 Test3 Testovich3", 3, 3, 3, "Test3", 3);
	personForSave[2].calculationSalary();
	personForSave[2].calculationPensionContributions();
	personForSave[2].calculationIncomeTax();

	personForSave[3] = PaymentWorked("Teschenko4 Test4 Testovich4", 4, 4, 4, "Test4", 4);
	personForSave[3].calculationSalary();
	personForSave[3].calculationPensionContributions();
	personForSave[3].calculationIncomeTax();

	personForSave[4] = PaymentWorked("Teschenko5 Test5 Testovich5", 5, 5, 5, "Test5", 5);
	personForSave[4].calculationSalary();
	personForSave[4].calculationPensionContributions();
	personForSave[4].calculationIncomeTax();

	if (save.is_open()) {
		for (int i = 0; i < 5; i++) {
			save << personForSave[i];
		}
		save.close();
	}

	ifstream load("test.txt", ios_base::in);
	if (load.is_open()) {
		for (int i = 0; i < 5; i++) {
			load >> personForLoad[i];
			personForLoad[i].calculationSalary();
			personForLoad[i].calculationPensionContributions();
			personForLoad[i].calculationIncomeTax();
			assert(personForLoad[i] == personForSave[i]);
		}
		load.close();
	}

	fstream clearFile("test.txt", ios::out);
	clearFile.close();
}

void testSaveLoadBinaryWorked() {
	PaymentWorked personForSave[5], personForLoad[5];
	ofstream saveB("testBinary.txt", ios_base::binary);

	personForSave[0] = PaymentWorked("Teschenko1 Test1 Testovich1", 1, 1, 1, "Test1", 1);
	personForSave[0].calculationSalary();
	personForSave[0].calculationPensionContributions();
	personForSave[0].calculationIncomeTax();

	personForSave[1] = PaymentWorked("Teschenko2 Test2 Testovich2", 2, 2, 2, "Test2", 2);
	personForSave[1].calculationSalary();
	personForSave[1].calculationPensionContributions();
	personForSave[1].calculationIncomeTax();

	personForSave[2] = PaymentWorked("Teschenko3 Test3 Testovich3", 3, 3, 3, "Test3", 3);
	personForSave[2].calculationSalary();
	personForSave[2].calculationPensionContributions();
	personForSave[2].calculationIncomeTax();

	personForSave[3] = PaymentWorked("Teschenko4 Test4 Testovich4", 4, 4, 4, "Test4", 4);
	personForSave[3].calculationSalary();
	personForSave[3].calculationPensionContributions();
	personForSave[3].calculationIncomeTax();

	personForSave[4] = PaymentWorked("Teschenko5 Test5 Testovich5", 5, 5, 5, "Test5", 5);
	personForSave[4].calculationSalary();
	personForSave[4].calculationPensionContributions();
	personForSave[4].calculationIncomeTax();

	if (saveB.is_open()) {
		for (int i = 0; i < 5; i++) {
			personForSave[i].binarySave(saveB);
		}
		saveB.close();
	}

	ifstream loadB("testBinary.txt", ios_base::binary);
	if (loadB.is_open()) {
		for (int i = 0; i < 5; i++) {
			personForLoad[i].binaryLoad(loadB);
			assert(personForLoad[i] == personForSave[i]);
		}
		loadB.close();
	}

	fstream clearFileB("testBinary.txt", ios::out);
	clearFileB.close();
}

void testSalaryCompany() {
	PaymentCompany test("Тестевский Тест Тестович", 5, 1, 10, "Тест", 500, 5);
	test.calculationSalary();
	assert(test.getSalary() == test.getHourlyPay() * test.getWorkingHours());
}

void testToStringyCompany() {
	PaymentCompany test("Тестевский Тест Тестович", 5, 1, 10, "Тест", 500, 5);
	test.calculationSalary();
	test.calculationIncomeTax();
	test.calculationPensionContributions();
	assert(strcmp(test.toString(), "Данные сотрудника: 'Тестевский Тест Тестович' \n Год поступления на работу: 1 \n Зарплата: 2500,00 р. \n Отчисления в пенсионный фонд: 25,00 р. \n Подоходный налог: 325,00 р. \n Должность: 'Тест' \n Плата за час: 500 р. \n Количество отработанных часов в месяце: 5 \n") == 0);
}

void testAssignmentyCompany() {
	PaymentCompany test("Тестевский Тест Тестович", 1, 1, 1, "Тест", 1, 1);
	test.calculationSalary();
	test.calculationIncomeTax();
	test.calculationPensionContributions();
	PaymentCompany test2("Тестевский2 Тест2 Тестович2", 2, 2, 2, "Тест2", 2, 2);
	test2.calculationSalary();
	test2.calculationIncomeTax();
	test2.calculationPensionContributions();
	test2 = test;
	assert(test2 == test);

	PaymentCompany test3("Тестевский3 Тест3 Тестович3", 3, 3, 3, "Тест3", 3, 3);
	test3.calculationSalary();
	test3.calculationIncomeTax();
	test3.calculationPensionContributions();
	PaymentCompany test4("Тестевский4 Тест4 Тестович4", 4, 4, 4, "Тест3", 4, 4);
	test4.calculationSalary();
	test4.calculationIncomeTax();
	test4.calculationPensionContributions();
	test4 = test3 = test;
	assert(test3 == test);
	assert(test4 == test3);

	PaymentCompany test5(test);
	test = test;
	assert(test == test5);
}

void testSaveLoadyCompany() {
	PaymentCompany personForSave[5], personForLoad[5];
	ofstream save("test.txt", ios_base::app);

	personForSave[0] = PaymentCompany("Teschenko1 Test1 Testovich1", 1, 1, 1, "Test1", 1, 1);
	personForSave[0].calculationSalary();
	personForSave[0].calculationPensionContributions();
	personForSave[0].calculationIncomeTax();

	personForSave[1] = PaymentCompany("Teschenko2 Test2 Testovich2", 2, 2, 2, "Test2", 2, 2);
	personForSave[1].calculationSalary();
	personForSave[1].calculationPensionContributions();
	personForSave[1].calculationIncomeTax();

	personForSave[2] = PaymentCompany("Teschenko3 Test3 Testovich3", 3, 3, 3, "Test3", 3, 3);
	personForSave[2].calculationSalary();
	personForSave[2].calculationPensionContributions();
	personForSave[2].calculationIncomeTax();

	personForSave[3] = PaymentCompany("Teschenko4 Test4 Testovich4", 4, 4, 4, "Test4", 4, 4);
	personForSave[3].calculationSalary();
	personForSave[3].calculationPensionContributions();
	personForSave[3].calculationIncomeTax();

	personForSave[4] = PaymentCompany("Teschenko5 Test5 Testovich5", 5, 5, 5, "Test5", 5, 5);
	personForSave[4].calculationSalary();
	personForSave[4].calculationPensionContributions();
	personForSave[4].calculationIncomeTax();

	if (save.is_open()) {
		for (int i = 0; i < 5; i++) {
			save << personForSave[i];
		}
		save.close();
	}

	ifstream load("test.txt", ios_base::in);
	if (load.is_open()) {
		for (int i = 0; i < 5; i++) {
			load >> personForLoad[i];
			personForLoad[i].calculationSalary();
			personForLoad[i].calculationPensionContributions();
			personForLoad[i].calculationIncomeTax();
			assert(personForLoad[i] == personForSave[i]);
		}
		load.close();
	}

	fstream clearFile("test.txt", ios::out);
	clearFile.close();
}

void testSaveLoadBinaryCompany() {
	PaymentCompany personForSave[5], personForLoad[5];
	ofstream saveB("testBinary.txt", ios_base::binary);

	personForSave[0] = PaymentCompany("Teschenko1 Test1 Testovich1", 1, 1, 1, "Test1", 1, 1);
	personForSave[0].calculationSalary();
	personForSave[0].calculationPensionContributions();
	personForSave[0].calculationIncomeTax();

	personForSave[1] = PaymentCompany("Teschenko2 Test2 Testovich2", 2, 2, 2, "Test2", 2, 2);
	personForSave[1].calculationSalary();
	personForSave[1].calculationPensionContributions();
	personForSave[1].calculationIncomeTax();

	personForSave[2] = PaymentCompany("Teschenko3 Test3 Testovich3", 3, 3, 3, "Test3", 3, 3);
	personForSave[2].calculationSalary();
	personForSave[2].calculationPensionContributions();
	personForSave[2].calculationIncomeTax();

	personForSave[3] = PaymentCompany("Teschenko4 Test4 Testovich4", 4, 4, 4, "Test4", 4, 4);
	personForSave[3].calculationSalary();
	personForSave[3].calculationPensionContributions();
	personForSave[3].calculationIncomeTax();

	personForSave[4] = PaymentCompany("Teschenko5 Test5 Testovich5", 5, 5, 5, "Test5", 5, 5);
	personForSave[4].calculationSalary();
	personForSave[4].calculationPensionContributions();
	personForSave[4].calculationIncomeTax();

	if (saveB.is_open()) {
		for (int i = 0; i < 5; i++) {
			personForSave[i].binarySave(saveB);
		}
		saveB.close();
	}

	ifstream loadB("testBinary.txt", ios_base::binary);
	if (loadB.is_open()) {
		for (int i = 0; i < 5; i++) {
			personForLoad[i].binaryLoad(loadB);
			assert(personForLoad[i] == personForSave[i]);
		}
		loadB.close();
	}

	fstream clearFileB("testBinary.txt", ios::out);
	clearFileB.close();
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

	testSaveLoad();
	testSaveLoadBinary();

	testSalaryWorked();
	testToStringyWorked();
	testAssignmentyWorked();
	testSaveLoadyWorked();
	testSaveLoadBinaryWorked();
	testSalaryCompany();
	testToStringyCompany();
	testAssignmentyCompany();
	testSaveLoadyCompany();
	testSaveLoadBinaryCompany();
}