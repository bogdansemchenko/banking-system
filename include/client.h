#pragma once

#include <string>
#include <vector>
#include "card.h"
#include "person.h"
#include "account .h"
#include "transaction.h"
#include "credit.h"

class Client : public Person {
private:
    std::vector<Card> cards;
    double cashRub;
    double cashUsd;
    double cashEur;
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;
    std::vector<Credit> credits;


public:
    Client(const std::string& name, int age, double rub, double usd, double eur);

    void addCard(const Card& card);
    void removeCard(const std::string& cardId);
    void setCashRub(double amount);
    void setCashUsd(double amount);
    void setCashEur(double amount);
    [[nodiscard]] double getCashRub() const;
    [[nodiscard]] double getCashUsd() const;
    [[nodiscard]] double getCashEur() const;
    void addAccount(const Account& account);
    void removeAccount(const std::string& accountId);
    [[nodiscard]] double getTotalBalance() const;
    void displayClientDetails() const;
    Card* findCardById(const std::string& cardId);
    bool createTransaction(Client& receiver, const std::string& senderCardId, const std::string& receiverCardId, double amount, const std::string& message = "No message");
    void addCredit(const Credit& credit);
    void displayCredits() const;
    void displayTransactions() const;
};


