#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(double balance, double tradingFees) : Account(balance), tradingFees(tradingFees) {
}

void CheckingAccount::credit(double cash) {
	Account::credit(cash);			// 尝试存钱
	if (!Account::debit(tradingFees)) {		// 如果余额不足以支付交易费
		Account::debit(cash);		// 撤销存钱
		std::cout << "Transaction fee exceeded account balance while crediting" << std::endl;
	}
}

bool CheckingAccount::debit(double cash) {
	if (Account::debit(cash)) {		// 尝试取钱
		if (!Account::debit(tradingFees)) {	// 如果余额不足以支付交易费
			Account::credit(cash);	// 撤销取钱
			std::cout << "Transaction fee exceeded account balance while debiting" << std::endl;
			return false;
		}
		return true;
	}
	return false;
}
