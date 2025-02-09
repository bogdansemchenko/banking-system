#pragma once

#include <vector>
#include <string>
#include "client.h"
#include "card.h"
#include "credit.h"

class Database {
private:
    std::vector<Client> clients;
    std::vector<Card> cards;
    std::vector<Credit> credits;

public:
    void addClient(const Client& client);
    [[nodiscard]] bool clientExists(const std::string& clientName) const;

    void addCard(const Card& card);
    void addCredit(const Credit& credit);

    void displayClients() const;
    void displayCards() const;
    void displayCredits() const;
};
