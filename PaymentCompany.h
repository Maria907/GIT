#pragma once
#include "Payment.h"

class PaymentCompany : public Payment {
public:
	PaymentCompany() : Payment() {
		profession = new char[2];
		strcpy(profession, " ");
		hourlyPay = 0;
		workingHours = 0;
	}

	PaymentCompany(const char* valueName, int valueDailySalary, int valueEmploymentYear, int valueWorkedDays, const char* valueProfession, int valueHourlyPay, int valueWorkingHours) : Payment(valueName, valueDailySalary, valueEmploymentYear, valueWorkedDays) {
		profession = new char[strlen(valueProfession) + 1];
		strcpy(profession, valueProfession);
		hourlyPay = valueHourlyPay;
		workingHours = valueWorkingHours;
	}

	PaymentCompany(const PaymentCompany& person) : Payment(person) {
		profession = new char[strlen(person.profession) + 1];
		strcpy(profession, person.profession);
		hourlyPay = person.hourlyPay;
		workingHours = person.workingHours;
	}

	~PaymentCompany();

	char* getProfession();
	int getHourlyPay();
	int getWorkingHours();

	void setProfession(const char* valueProfession);
	void setHourlyPay(int valueHourlyPay);
	void setWorkingHours(int valueWorkingHours);

	void calculationSalary();

	friend bool operator == (PaymentCompany& person1, PaymentCompany& person2);
	friend bool operator != (PaymentCompany& person1, PaymentCompany& person2);

	PaymentCompany operator = (const PaymentCompany& person);

	friend ostream& operator << (ostream& out, const PaymentCompany& person);
	friend istream& operator >> (istream& in, PaymentCompany& person);
	friend ofstream& operator << (ofstream& out, const PaymentCompany& person);

	char* toString();

	void binarySave(ofstream& save);
	void binaryLoad(ifstream& load);

private:
	char* profession;
	int hourlyPay;
	int workingHours;
};