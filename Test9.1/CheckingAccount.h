#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(double balance, double tradingFees);
    void credit(double cash) override;
    bool debit(double cash) override;
private:
    double tradingFees;
};

#endif //CHECKINGACCOUNT_H
