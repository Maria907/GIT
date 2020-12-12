#pragma once
#include "Payment.h"

class PaymentСompany : public Payment {
public:
	PaymentСompany() : Payment() {
		profession = new char[2];
		strcpy(profession, " ");
		hourlyPay = 0;
		workingHours = 0;
	}

	PaymentСompany(const char* valueName, int valueDailySalary, int valueEmploymentYear, int valueWorkedDays, const char* valueProfession, int valueHourlyPay, int valueWorkingHours) : Payment(valueName, valueDailySalary, valueEmploymentYear, valueWorkedDays) {
		profession = new char[strlen(valueProfession) + 1];
		strcpy(profession, valueProfession);
		hourlyPay = valueHourlyPay;
		workingHours = valueWorkingHours;
	}

	PaymentСompany(const PaymentСompany& person) : Payment(person) {
		profession = new char[strlen(person.profession) + 1];
		strcpy(profession, person.profession);
		hourlyPay = person.hourlyPay;
		workingHours = person.workingHours;
	}

	~PaymentСompany();

	char* getProfession();
	int getHourlyPay();
	int getWorkingHours();

	void setProfession(const char* valueProfession);
	void setHourlyPay(int valueHourlyPay);
	void setWorkingHours(int valueWorkingHours);

	void calculationSalary();
	void calculationPensionContributions();
	void calculationIncomeTax();

	friend bool operator == (PaymentСompany& person1, PaymentСompany& person2);
	friend bool operator != (PaymentСompany& person1, PaymentСompany& person2);

	PaymentСompany operator = (const PaymentСompany& person);

	friend ostream& operator << (ostream& out, const PaymentСompany& person);
	friend istream& operator >> (istream& in, PaymentСompany& person);
	friend ofstream& operator << (ofstream& out, const PaymentСompany& person);

	char* toString();

	void binarySave(ofstream& save);
	void binaryLoad(ifstream& load);

private:
	char* profession;
	int hourlyPay;
	int workingHours;
};