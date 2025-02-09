#include "../include/bank.h"
#include <iostream>

Bank::Bank(const std::string& name, const std::string& owner, int year, double budget, double rating, double value, int safetyCoefficient)
    : bankName(name), ownerName(owner), yearEstablished(year), bankBudget(budget), bankRating(rating), bankValue(value), safetyCoefficient(safetyCoefficient) {
    if (safetyCoefficient < 1) {
        safetyCoefficient = 1;
    } else if (safetyCoefficient > 10) {
        safetyCoefficient = 10;
    }
}

std::string Bank::getBankName() const {
    return bankName;
}

std::string Bank::getOwnerName() const {
    return ownerName;
}

int Bank::getYearEstablished() const {
    return yearEstablished;
}

double Bank::getBankBudget() const {
    return bankBudget;
}

double Bank::getBankRating() const {
    return bankRating;
}

double Bank::getBankValue() const {
    return bankValue;
}
int Bank::getSafetyCoefficient() const {
    return safetyCoefficient;
}
void Bank::setSafetyCoefficient(int coefficient) {
    safetyCoefficient = coefficient;
}

void Bank::updateBankBudget(double amount) {
    bankBudget += amount;
    std::cout << "Bank budget updated. New budget: " << bankBudget << "\n";
}

void Bank::setBankBudget(double amount) {
    bankBudget = amount;
}

void Bank::updateBankValue(double amount) {
    bankValue += amount;
    std::cout << "Bank value updated. New value: " << bankValue << "\n";
}

void Bank::displayBankInfo() const {
    std::cout << "Bank Name: " << bankName << "\n";
    std::cout << "Owner Name: " << ownerName << "\n";
    std::cout << "Year Established: " << yearEstablished << "\n";
    std::cout << "Bank Budget: " << bankBudget << " RUB\n";
    std::cout << "Bank Rating: " << bankRating << "/10\n";
    std::cout << "Bank Value: " << bankValue << " RUB\n";
    std::cout << "Safety Coefficient: " << safetyCoefficient << "/10\n";
}

Database& Bank::getDatabase() {
    return db;
}

CurrencyExchange& Bank::getExchangeRates() {
    return exchangeRates;
}
void Bank::updateSafetyCoefficient(int coefficient) {
    if (coefficient < 1) {
        safetyCoefficient = 1;
    } else if (coefficient > 10) {
        safetyCoefficient = 10;
    } else {
        safetyCoefficient = coefficient;
    }
}
