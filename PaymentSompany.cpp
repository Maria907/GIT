#include "Payment.h"
#include "PaymentСompany.h"

PaymentСompany::~PaymentСompany() {
	delete profession;
}

char* PaymentСompany::getProfession() {
	return profession;
}

int PaymentСompany::getHourlyPay() {
	return hourlyPay;
}

int PaymentСompany::getWorkingHours() {
	return workingHours;
}

void PaymentСompany::setProfession(const char* valueProfession) {
	delete profession;
	profession = new char[strlen(valueProfession) + 1];
	strcpy(profession, valueProfession);
}

void PaymentСompany::setHourlyPay(int valueHourlyPay) {
	hourlyPay = valueHourlyPay;
}

void PaymentСompany::setWorkingHours(int valueWorkingHours) {
	workingHours = valueWorkingHours;
}

void PaymentСompany::calculationSalary() {
	salary = hourlyPay * workingHours;	
}

void PaymentСompany::calculationPensionContributions() {
	Payment::calculationPensionContributions();
}

void PaymentСompany::calculationIncomeTax() {
	Payment::calculationIncomeTax();
}

bool operator == (PaymentСompany& person1, PaymentСompany& person2) {
	return (strcmp(person1.name, person2.name) == 0
		&& person1.dailySalary == person2.dailySalary
		&& person1.employmentYear == person2.employmentYear
		&& person1.workedDays == person2.workedDays
		&& person1.salary == person2.salary
		&& person1.pensionContributions == person2.pensionContributions
		&& person1.incomeTax == person2.incomeTax
		&& (strcmp(person1.profession, person2.profession) == 0)
		&& person1.hourlyPay == person2.hourlyPay
		&& person1.workingHours == person2.workingHours);
}

bool operator != (PaymentСompany& person1, PaymentСompany& person2) {
	return !(person1 == person2);
}

PaymentСompany PaymentСompany::operator = (const PaymentСompany& person) {
	if (strcmp(name, person.name) != 0) {
		delete[] name;
		name = new char[strlen(person.name) + 1];
		strcpy(name, person.name);
	}
	if (strcmp(profession, person.profession) != 0) {
		delete[] profession;
		profession = new char[strlen(person.profession) + 1];
		strcpy(profession, person.profession);
	}
	dailySalary = person.dailySalary;
	employmentYear = person.employmentYear;
	workedDays = person.workedDays;
	salary = person.salary;
	pensionContributions = person.pensionContributions;
	incomeTax = person.incomeTax;
	hourlyPay = person.hourlyPay;
	workingHours = person.workingHours;

	return *this;
}

ostream& operator << (ostream& out, const PaymentСompany& person) {
	out << "Данные сотрудника: " << person.name << endl
		<< " Год поступления на работу: " << person.employmentYear << endl
		<< " Зарплата: " << person.salary << " р." << endl
		<< " Отчисления в пенсионный фонд: " << person.pensionContributions << " р." << endl
		<< " Подоходный налог: " << person.incomeTax << " р." << endl
		<< " Должность: " << person.profession << endl
		<< " Плата за час: " << person.hourlyPay << " р." << endl
		<< " Количество отработанных часов в месяце: " << person.workingHours << endl;
	return out;
}


istream& operator >> (istream& in, PaymentСompany& person) {
	delete[] person.name;
	person.name = new char[255];
	in.getline(person.name, 255, ';');
	in >> person.dailySalary;
	in >> person.employmentYear;
	in >> person.workedDays;
	delete[] person.profession;
	person.profession = new char[255];
	in.getline(person.profession, 255, ';');
	in >> person.hourlyPay;
	in >> person.workingHours;
	return in;
}

ofstream& operator << (ofstream& out, const PaymentСompany& person) {
	out << person.name << "; " << person.dailySalary << " " << person.employmentYear << " " << person.workedDays << person.profession << "; " << person.hourlyPay << " " << person.workingHours;
	return out;
}

char* PaymentСompany::toString() {
	char* stringObj = new char[strlen(name)
		+ strlen(profession)
		+ sizeof(employmentYear)
		+ sizeof(salary)
		+ sizeof(pensionContributions)
		+ sizeof(incomeTax)
		+ sizeof(hourlyPay)
		+ sizeof(workingHours)
		+ 232];
	sprintf(stringObj, "Данные сотрудника: '%s' \n Год поступления на работу: %d \n Зарплата: %.2f р. \n Отчисления в пенсионный фонд: %.2f р. \n Подоходный налог: %.2f р. \n Должность: '%s' \n Плата за час: %d р. \n Количество отработанных часов в месяце: %d \n",
		name, employmentYear, salary, pensionContributions, incomeTax, profession, hourlyPay, workingHours);
	return (stringObj);
}

void PaymentСompany::binarySave(ofstream& save) {
	if (save.is_open()) {
		save.write((char*)this, sizeof(*this));
	}
}

void PaymentСompany::binaryLoad(ifstream& load) {
	PaymentСompany result;
	delete[] result.name;
	delete[] result.profession;
	result.name = new char[255];
	result.profession = new char[255];
	if (load.is_open()) {
		load.read((char*)&result, sizeof(result));
		*this = result;
		result.name = NULL;
		result.profession = NULL;
	}
}
