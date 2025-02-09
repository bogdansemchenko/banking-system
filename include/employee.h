#pragma once

#include "person.h"
#include "currencyExchange.h"
#include "credit.h"
#include "bank.h"

class Employee : public Person {
private:
    Bank& bank;

public:
    Employee(const std::string& name, int age, Bank& bank);

    void createCardForClient(Client& client, const std::string& cardId, const std::string& cardType, const std::string& expiryDate, const std::string& cvc, double initialBalance, int password, const std::string& owner);

    void exchangeCurrency(Client& client, double amount, const std::string& fromCurrency, const std::string& toCurrency);

    void createCreditForClient(Client& client, const std::string& creditId, double principal, double rate, int term);
};
