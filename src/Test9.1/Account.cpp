#include "Account.h"
#include <iostream>

Account::Account(double balance) : balance(balance) {
}

Account::~Account() {
}

void Account::credit(double cash) {
	balance += cash;
}

bool Account::debit(double cash) {
	if (balance >= cash) {
		balance -= cash;
		return true;
	}
	std::cout << "Debit amount exceeded account balance" << std::endl;
	return false;
}

double Account::getBalance() const {
	return balance;
}
