#include "Payment.h"
#include "PaymentWorked.h"

PaymentWorked::~PaymentWorked() {
	delete job;
}

char* PaymentWorked::getJob() {
	return job;
}

int PaymentWorked::getAllowance() {
	return allowance;
}

void PaymentWorked::setJob(const char* valueJob) {
	delete job;
	job = new char[strlen(valueJob) + 1];
	strcpy(job, valueJob);
}

void PaymentWorked::setAllowance(int valueAllowance) {
	allowance = valueAllowance;
}

void PaymentWorked::calculationSalary() {
	salary = (dailySalary + allowance) * workedDays;
}

bool operator == (PaymentWorked& person1, PaymentWorked& person2) {
	return (strcmp(person1.name, person2.name) == 0
		&& person1.dailySalary == person2.dailySalary
		&& person1.employmentYear == person2.employmentYear
		&& person1.workedDays == person2.workedDays
		&& person1.salary == person2.salary
		&& person1.pensionContributions == person2.pensionContributions
		&& person1.incomeTax == person2.incomeTax
		&& (strcmp(person1.job, person2.job) == 0)
		&& person1.allowance == person2.allowance);
}

bool operator != (PaymentWorked& person1, PaymentWorked& person2) {
	return !(person1 == person2);
	
}

PaymentWorked PaymentWorked::operator = (const PaymentWorked& person) {
	if (strcmp(name, person.name) != 0) {
		delete[] name;
		name = new char[strlen(person.name) + 1];
		strcpy(name, person.name);
	}
	if (strcmp(job, person.job) != 0) {
		delete[] job;
		job = new char[strlen(person.job) + 1];
		strcpy(job, person.job);
	}
	dailySalary = person.dailySalary;
	employmentYear = person.employmentYear;
	workedDays = person.workedDays;
	salary = person.salary;
	pensionContributions = person.pensionContributions;
	incomeTax = person.incomeTax;
	allowance = person.allowance;
	
	return *this;
}

ostream& operator << (ostream& out, const PaymentWorked& person) {
	out << "Данные сотрудника: " << person.name << endl
		<< " Оклад: " << person.dailySalary << " р." << endl
		<< " Год поступления на работу: " << person.employmentYear << endl
		<< " Кол-во отработанных дней в месяце: " << person.workedDays << endl
		<< " Зарплата: " << person.salary << " р." << endl
		<< " Отчисления в пенсионный фонд: " << person.pensionContributions << " р." << endl
		<< " Подоходный налог: " << person.incomeTax << " р." << endl
		<< " Должность: " << person.job << endl 
		<< " Надбавка за должность: " << person.allowance << " р." << endl;
	return out;
}


istream& operator >> (istream& in, PaymentWorked& person) {
	delete[] person.name;
	person.name = new char[255];
	in.getline(person.name, 255, ';');
	in >> person.dailySalary;
	in >> person.employmentYear;
	in >> person.workedDays;
	delete[] person.job;
	person.job = new char[255];
	in.getline(person.job, 255, ';');
	in >> person.allowance;
	return in;
}

ofstream& operator << (ofstream& out, const PaymentWorked& person) {
	out << person.name << "; " << person.dailySalary << " " << person.employmentYear << " " << person.workedDays << person.job << "; " << person.allowance;
	return out;
}

char* PaymentWorked::toString() {
	char* stringObj = new char[strlen(name)
		+ strlen(job)
		+ sizeof(dailySalary)
		+ sizeof(employmentYear)
		+ sizeof(workedDays)
		+ sizeof(salary)
		+ sizeof(pensionContributions)
		+ sizeof(incomeTax)
		+ sizeof(allowance)
		+ 251];
	sprintf(stringObj, "Данные сотрудника: '%s' \n Оклад: %d р. \n Год поступления на работу: %d \n Кол-во отработанных дней в месяце: %d \n Зарплата: %.2f р. \n Отчисления в пенсионный фонд: %.2f р. \n Подоходный налог: %.2f р. \n Должность: '%s' \n Надбавка за должность: %d р. \n",
		name, dailySalary, employmentYear, workedDays, salary, pensionContributions, incomeTax, job, allowance);
	return (stringObj);
}

void PaymentWorked::binarySave(ofstream& save) {
	if (save.is_open()) {
		save.write((char*)this, sizeof(*this));
	}
}

void PaymentWorked::binaryLoad(ifstream& load) {
	PaymentWorked result;
	delete[] result.name;
	delete[] result.job;
	result.name = new char[255];
	result.job = new char[255];
	if (load.is_open()) {
		load.read((char*)&result, sizeof(result));
		*this = result;
		result.name = NULL;
		result.job = NULL;
	}
}
