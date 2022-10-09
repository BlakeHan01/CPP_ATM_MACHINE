//
// Created by Blake Han on 2022/10/8.
//

#ifndef CPP_ATM_MACHINE_BANKACCOUNT_H
#define CPP_ATM_MACHINE_BANKACCOUNT_H

#include <string>
#include <utility>
#include <vector>
#include "transaction.h"

using namespace std;



class bankAccount{
private:
    int account_no;
    static int increment;
    string password;
    int balance = 5000;
public:
    int getAccountNo();

    const string &getPassword() const;

    void setPassword(const string &password);

    int getBalance() const;

    void setBalance(int balance);

    const vector<transaction> &getTransactions() const;

    void addTransactions(const transaction &transactions);

private:
    vector<transaction> transactions;
public:
    explicit bankAccount(string password);

    bankAccount(){
        bankAccount::account_no = increment;
        increment++;
    };
};

int bankAccount::increment = 1;


bankAccount::bankAccount(string password) {
    this->password = move(password);
}

//getters and setters
int bankAccount::getAccountNo() {
    return account_no;
}

const string &bankAccount::getPassword() const {
    return password;
}

void bankAccount::setPassword(const string &password) {
    bankAccount::password = password;
}

int bankAccount::getBalance() const {
    return balance;
}

void bankAccount::setBalance(int balance1) {
    bankAccount::balance += balance1;
}

const vector<transaction> &bankAccount::getTransactions() const {
    return transactions;
}

void bankAccount::addTransactions(const transaction &transaction) {
    bankAccount::transactions.push_back(transaction);
    if(transaction.getType().compare("Deposit")==0){
        bankAccount::setBalance(transaction.getAmount());
    } else{
        bankAccount::setBalance(-transaction.getAmount());
    }
}

#endif //CPP_ATM_MACHINE_BANKACCOUNT_H
