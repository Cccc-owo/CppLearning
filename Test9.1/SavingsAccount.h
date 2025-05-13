#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(double balance, double interestRate);
    double calculateInterest() const;
    using Account::credit;
    using Account::debit;
private:
    double interestRate;
};

#endif //SAVINGSACCOUNT_H
