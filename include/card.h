#pragma once

#include <string>
#include <iostream>

class Card {
private:
    std::string id;
    std::string cardType;
    std::string expiryDate;
    std::string cvc;
    double balance;
    int password;
    std::string ownerName;

public:
    Card(const std::string& cardId, const std::string& type, const std::string& expiry, const std::string& cvcCode, double initialBalance, int passwordCard, const std::string& owner);
    [[nodiscard]] std::string getId() const;
    [[nodiscard]] int getPassword() const;
    [[nodiscard]] std::string getCardType() const;
    [[nodiscard]] std::string getExpiryDate() const;
    [[nodiscard]] std::string getCvc() const;
    [[nodiscard]] double getBalance() const;
    void setBalance(double newBalance);
    bool withdraw(double amount);
    void deposit(double amount);
    void displayCardDetails() const;
    [[nodiscard]] std::string getOwnerName() const;
};

