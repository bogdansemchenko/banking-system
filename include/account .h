#pragma once

#include <string>
#include <vector>
#include "card.h"
#

class Account {
private:
    std::string id;
    std::vector<Card> linkedCards;

public:
    Account(const std::string& accountId);

    [[nodiscard]] std::string getId() const;
    [[nodiscard]] double getBalance() const;

    void addCard(const Card& card);
    void removeCard(const std::string& cardId);

    void displayAccountDetails() const;
};
