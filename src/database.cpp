#include "../include/database.h"
#include <iostream>

void Database::addClient(const Client& client) {
    if (!clientExists(client.getName())) {
        clients.push_back(client);
        std::cout << "Client " << client.getName() << " added to the database.\n";
    } else {
        std::cout << "Client " << client.getName() << " already exists in the database.\n";
    }
}

bool Database::clientExists(const std::string& clientName) const {
    for (const auto& client : clients) {
        if (client.getName() == clientName) {
            return true;
        }
    }
    return false;
}

void Database::addCard(const Card& card) {
    cards.push_back(card);
    std::cout << "Card " << card.getId() << " added to the database.\n";
}

void Database::addCredit(const Credit& credit) {
    credits.push_back(credit);
    std::cout << "Credit " << credit.getId() << " added to the database.\n";
}

void Database::displayClients() const {
    std::cout << "Clients in the database:\n";
    for (const auto& client : clients) {
        std::cout << client.getName() << "\n";
    }
}

void Database::displayCards() const {
    std::cout << "Cards in the database:\n";
    for (const auto& card : cards) {
        std::cout << card.getId() << "\n";
    }
}

void Database::displayCredits() const {
    std::cout << "Credits in the database:\n";
    for (const auto& credit : credits) {
        std::cout << credit.getId() << "\n";
    }
}

