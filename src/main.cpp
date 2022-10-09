//
// Created by Blake Han on 2022/10/8.
//

#pragma once
#include <iostream>
#include "bankAccount.h"
#include "transaction.h"
#include <string>
using namespace std;

int main(){
    bankAccount bankAccounts[10];
    static int i=-1;
    for(bankAccount & ba : bankAccounts){
        ba.setPassword(to_string(++i));
    }
    int accountNo;
    int password;
    while(accountNo != password || accountNo > 10 || accountNo < 1) {
        cout << "Login Window:" << endl;
        cout << "=============" << endl;
        cout << "Enter your Account no:";
        cin >> accountNo;
        cout << "Enter your password:";
        cin >> password;
        cout << "\n";
    }

    int choice = 0;
    bankAccount& curr = bankAccounts[accountNo-1];
    //a is for detecting whether a user pressed enter
    int a;
    int amount;
    while(choice!=5) {
        switch(choice) {
            case 0:
                cout << "Main Window" << endl;
                cout << "===========" << endl;
                cout << "Choose one of the following options:" << endl;
                cout << "(1)Show balance\n" << "(2)Deposit\n"
                     << "(3)Withdraw\n(4)Show All Transactions\n(5)Exit\nEnter your choice: ";
                cin >> choice;
                while (choice < 1 || choice > 5) {
                    cout << "Choose between 1 and 5:";
                    cin >> choice;
                }
                break;
            case 1:
                cout << "Main Window->Show Balance\n";
                cout << "=========\n";
                cout << "Your current balance is: ";
                cout << bankAccounts[accountNo-1].getBalance();
                cout << "\n----------\n";
                cout << "Press enter to go back to the Main Window";
                cin.get();
                while(true) {
                    if (cin.get() == '\n') {
                        break;
                    }
                }
                choice = 0;
                break;
            case 2:
                cout << "Main Window->Deposit(Enter the following information)\n";
                cout << "=========\n";
                cout << "The amount you want to deposit: ";

                cin >> amount;
                if(amount < 0){
                    cout << "\nSorry the number you entered is negative ";
                    cout << "\nIf you mean to withdraw, please go to withdraw\n";
                } else {
                    bankAccounts[accountNo-1].addTransactions(transaction("Deposit", amount));
                    cout << "\n----------\n";
                    cout << "Well done. This was added to your balance successfully... ";
                }
                cout << "Press enter to go back to the Main Window";
                cin.get();
                while(true) {
                    if (cin.get() == '\n') {
                        break;
                    }
                }
                choice = 0;
                break;
            case 3:
                cout << "Main Window->Withdraw(Enter the following information)\n";
                cout << "=========\n";
                cout << "The amount you want to withdraw: ";
                cin >> amount;
                if(amount < 0 || amount > curr.getBalance()){
                    cout << "\nSorry you should check your balance to withdraw a valid amount which is less than your balance and larger than 0\n";
                } else {
                    bankAccounts[accountNo - 1].addTransactions(transaction("Withdraw", amount));
                    cout << "\n----------\n";
                    cout << "You have successfully withdrawn " << amount << " from your account \n";
                }
                cout << "Press enter to go back to the Main Window";
                cin.get();
                while(true) {
                    if (cin.get() == '\n') {
                        break;
                    }
                }
                choice = 0;
                break;
            case 4:
                cout << "Main Window->Show All Transaction\n";
                cout << "=========\n";
                cout << "Account no:" << accountNo << "\n";
                cout << "----------------" << endl;
                cout << "Date                            | Type           | Amount" << endl;
                for(transaction t: bankAccounts[accountNo-1].getTransactions()){
                    cout << t.getThisDate() << "        " << t.getType() << "          " << t.getAmount() << endl;
                }
                cout << "Press enter to go back to the Main Window";
                cin.get();
                while(true) {
                    if (cin.get() == '\n') {
                        break;
                    }
                }
                choice = 0;
                break;
        }
    }

}
