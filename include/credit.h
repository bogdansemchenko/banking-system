
#pragma once
#include <string>
#include <iostream>


class Client;

class Credit {
private:
    std::string id;
    double principalAmount;
    double interestRate;
    int termMonths;
    double monthlyPayment;
    bool isActive;
    Client* client;

    void calculateMonthlyPayment();

public:
    Credit(const std::string& creditId, double principal, double rate, int term, Client* clientPtr);

    [[nodiscard]] std::string getId() const;
    [[nodiscard]] double getPrincipalAmount() const;
    [[nodiscard]] double getInterestRate() const;
    [[nodiscard]] int getTermMonths() const;
    [[nodiscard]] double getMonthlyPayment() const;
    [[nodiscard]] bool getIsActive() const;
    [[nodiscard]] Client* getClient() const;

    void makePayment(double amount);
    void displayCreditDetails() const;
};

#include "client.h"
