#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    Account(double balance);
    virtual ~Account();
    virtual void credit(double cash);
    virtual bool debit(double cash);
    virtual double getBalance() const;
private:
    double balance;
};

#endif //ACCOUNT_H
