//
// Created by Blake Han on 2022/10/8.
//

#ifndef CPP_ATM_MACHINE_TRANSACTION_H
#define CPP_ATM_MACHINE_TRANSACTION_H

#include <chrono>
#include <string>
#include <utility>
#include "date.h"
using namespace std;
using namespace date;

class transaction{
private:
    string type;
    int amount;
    chrono::time_point<chrono::system_clock> thisDate;
public:
    const chrono::time_point<chrono::system_clock> &getThisDate() const;

    void setThisDate(const chrono::time_point<chrono::system_clock> &thisDate);

public:

    const string &getType() const;

    int getAmount() const;

    void setAmount(int amount);

public:
    transaction(string type, int amount);

};


transaction::transaction(string type, int amount) {
    transaction::type = move(type);
    transaction::amount = amount;
    setThisDate(thisDate);
}

const string &transaction::getType() const {
    return type;
}

int transaction::getAmount() const {
    return amount;
}

void transaction::setAmount(int amount) {
    transaction::amount = amount;
}

const chrono::time_point<chrono::system_clock> &transaction::getThisDate() const {
    return thisDate;
}

void transaction::setThisDate(const chrono::time_point<chrono::system_clock> &thisDate) {
    auto tp = std::chrono::system_clock::now();
    cout << tp;
//    auto dp = floor<days>(tp);
//    auto ymd = year_month_day{dp};
//    auto time = make_time(tp-dp);
    transaction::thisDate = tp;
}

#endif //CPP_ATM_MACHINE_TRANSACTION_H
