#pragma once

#include <string>
#include "database.h"
#include "currencyExchange.h"

class Bank {
private:
    std::string bankName;
    std::string ownerName;
    int yearEstablished;
    double bankBudget;
    double bankRating;
    double bankValue;
    int safetyCoefficient;
    CurrencyExchange exchangeRates;
    Database db;

public:
    Bank(const std::string& name, const std::string& owner, int year, double budget, double rating, double value, int safetyCoefficient = 5);

    [[nodiscard]] std::string getBankName() const;
    [[nodiscard]] std::string getOwnerName() const;
    [[nodiscard]] int getYearEstablished() const;
    [[nodiscard]] double getBankBudget() const;
    [[nodiscard]] double getBankRating() const;
    [[nodiscard]] double getBankValue() const;
    [[nodiscard]] int getSafetyCoefficient() const;
    void setSafetyCoefficient(int coefficient);
    void setBankBudget(double budget);
    void updateBankBudget(double amount);
    void updateBankValue(double amount);
    void updateSafetyCoefficient(int coefficient);
    void displayBankInfo() const;
    Database& getDatabase();
    CurrencyExchange& getExchangeRates();
};
