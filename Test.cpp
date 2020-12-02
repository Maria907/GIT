#include "Payment.h"

void Payment::testSalary() {
	setDailySalary(5);
	setWorkedDays(10);
	calculationSalary();
	assert(getSalary() == getDailySalary() * getWorkedDays()); 
}

void Payment::testPensionContributions() {
	setDailySalary(5);
	setWorkedDays(10);
	calculationSalary();
	calculationPensionContributions();
	assert(getPensionContributions() == getSalary() * 0.01); 
}

void Payment::testIncomeTax() {
	setDailySalary(5);
	setWorkedDays(10);
	calculationSalary();
	calculationIncomeTax();
	assert(getIncomeTax() == getSalary() * 0.13); 
}





	
