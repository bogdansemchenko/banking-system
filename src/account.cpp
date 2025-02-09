#include "../include/account .h"
#include <iostream>

Account::Account(const std::string& accountId) : id(accountId) {}

std::string Account::getId() const {
    return id;
}

double Account::getBalance() const {
    double totalBalance = 0.0;
    for (const auto& card : linkedCards) {
        totalBalance += card.getBalance();
    }
    return totalBalance;
}

void Account::addCard(const Card& card) {
    linkedCards.push_back(card);
    std::cout << "Card with type: " << card.getCardType() << " successfully added to account.\n";
}

void Account::removeCard(const std::string& cardId) {
    for (auto it = linkedCards.begin(); it != linkedCards.end(); ++it) {
        if (it->getId() == cardId) {
            linkedCards.erase(it);
            std::cout << "Card with ID: " << cardId << " successfully removed from account.\n";
            return;
        }
    }
    std::cout << "Card with ID: " << cardId << " not found in account.\n";
}

void Account::displayAccountDetails() const {
    std::cout << "Account ID: " << id << "\n";
    std::cout << "Linked Cards:\n";
    for (const auto& card : linkedCards) {
        std::cout << "  - Card ID: " << card.getId()
                  << ", Balance: " << card.getBalance() << " RUB\n";
    }
    std::cout << "Total Account Balance: " << getBalance() << " RUB\n";
}

