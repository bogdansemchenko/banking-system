#pragma once

#include "card.h"
#include "client.h"
#include <iostream>

class ATM {
private:
    double atmBalanceRub;
    std::string serialNumber;

public:
    ATM(double initialBalance, const std::string& serial);
    void withdrawMoney(Client &client, Card &card, double amount, int enteredPassword);
    void depositMoney(Client &client, Card &card, double amount, int enteredPassword);

    void displayATMBalance() const;
    void displayATMSN() const;

    void displayCardBalance(const Card &card) const;
};

