#pragma once
#include "Payment.h"

class PaymentWorked : public Payment {
public:
	PaymentWorked() : Payment() {
		job = new char[2];
		strcpy(job, " ");
		allowance = 0;
	}

	PaymentWorked(const char* valueName, int valueDailySalary, int valueEmploymentYear, int valueWorkedDays, const char* valueJob, int valueAllowance) : Payment(valueName, valueDailySalary, valueEmploymentYear, valueWorkedDays) {
		job = new char[strlen(valueJob) + 1];
		strcpy(job, valueJob);
		allowance = valueAllowance;
	}

	PaymentWorked(const PaymentWorked& person) : Payment(person) {
		job = new char[strlen(person.job) + 1];
		strcpy(job, person.job);
		allowance = person.allowance;
	}

	~PaymentWorked();

	char* getJob();
	int getAllowance();

	void setJob(const char* valueJob);
	void setAllowance(int valueAllowance);

	void calculationSalary();
	void calculationPensionContributions();
	void calculationIncomeTax();

	friend bool operator == (PaymentWorked& person1, PaymentWorked& person2);
	friend bool operator != (PaymentWorked& person1, PaymentWorked& person2);

	PaymentWorked operator = (const PaymentWorked& person);

	friend ostream& operator << (ostream& out, const PaymentWorked& person);
	friend istream& operator >> (istream& in, PaymentWorked& person);
	friend ofstream& operator << (ofstream& out, const PaymentWorked& person);

	char* toString();

	void binarySave(ofstream& save);
	void binaryLoad(ifstream& load);
	
private:
	char* job;
	int allowance;
};