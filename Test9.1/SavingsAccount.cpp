#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance), interestRate(interestRate) {
}

double SavingsAccount::calculateInterest() const {
	return getBalance() * interestRate * 0.01;
}
