#include "../include/client.h"
#include <iostream>

Client::Client(const std::string& name, int age, double rub, double usd, double eur)
    : Person(name, age), cashRub(rub), cashUsd(usd), cashEur(eur) {}

void Client::addCard(const Card& card) {
    cards.push_back(card);
    std::cout << "Card with ID: " << card.getId() << " successfully added to client.\n";
}

void Client::removeCard(const std::string& cardId) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if (it->getId() == cardId) {
            cards.erase(it);
            std::cout << "Card with ID: " << cardId << " successfully removed from client.\n";
            return;
        }
    }
    std::cout << "Card with ID: " << cardId << " not found in client's card list.\n";
}

void Client::setCashRub(double amount) { cashRub = amount; }
void Client::setCashUsd(double amount) { cashUsd = amount; }
void Client::setCashEur(double amount) { cashEur = amount; }
double Client::getCashRub() const { return cashRub; }
double Client::getCashUsd() const { return cashUsd; }
double Client::getCashEur() const { return cashEur; }

void Client::addAccount(const Account& account) {
    accounts.push_back(account);
    std::cout << "Account with ID: " << account.getId() << " successfully added to client.\n";
}

void Client::removeAccount(const std::string& accountId) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getId() == accountId) {
            accounts.erase(it);
            std::cout << "Account with ID: " << accountId << " successfully removed from client.\n";
            return;
        }
    }
    std::cout << "Account with ID: " << accountId << " not found in client's account list.\n";
}

double Client::getTotalBalance() const {
    double totalBalance = cashRub;
    for (const auto& card : cards) {
        totalBalance += card.getBalance();
    }
    return totalBalance;
}

void Client::displayClientDetails() const {
    Person::displayInfo();
    std::cout << "Cash in Rubles: " << cashRub << " RUB\n";
    std::cout << "Cash in USD: " << cashUsd << " USD\n";
    std::cout << "Cash in EUR: " << cashEur << " EUR\n";

    std::cout << "Linked Cards:\n";
    for (const auto& card : cards) {
        std::cout << "  - Card ID: " << card.getId()
                  << ", Balance: " << card.getBalance() << " RUB\n";
    }
}

Card* Client::findCardById(const std::string& cardId) {
    for (auto& card : cards) {
        if (card.getId() == cardId) {
            return &card;
        }
    }
    std::cout << "Card with ID: " << cardId << " not found.\n";
    return nullptr;
}

bool Client::createTransaction(Client& receiver, const std::string& senderCardId, const std::string& receiverCardId, double amount, const std::string& message) {
    Card* senderCard = findCardById(senderCardId);
    if (!senderCard) {
        std::cout << "Transaction failed: Sender card not found.\n";
        return false;
    }

    Card* receiverCard = receiver.findCardById(receiverCardId);
    if (!receiverCard) {
        std::cout << "Transaction failed: Receiver card not found.\n";
        return false;
    }

    if (senderCard->getBalance() < amount) {
        std::cout << "Transaction failed: Insufficient funds on sender's card.\n";
        return false;
    }

    senderCard->withdraw(amount);
    receiverCard->deposit(amount);
    Transaction transaction(*senderCard, *receiverCard, amount, message);

    transactions.push_back(transaction);
    receiver.transactions.push_back(transaction);

    std::cout << "Transaction successful: " << amount << " RUB transferred from Card ID "
              << senderCardId << " to Card ID " << receiverCardId << ".\n";

    return true;
}


void Client::addCredit(const Credit& credit) {
    credits.push_back(credit);
}

void Client::displayCredits() const {
    std::cout << "Client's Credits:\n";
    for (const auto& credit : credits) {
        credit.displayCreditDetails();
        std::cout << "\n";
    }
}

void Client::displayTransactions() const {
    std::cout << "Client's Transactions:\n";
    for (const auto& transaction : transactions) {
        transaction.displayTransactionDetails();
        std::cout << "\n";
    }
}

