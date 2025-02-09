#include "../include/card.h"

Card::Card(const std::string& cardId, const std::string& type, const std::string& expiry, const std::string& cvcCode, double initialBalance, int passwordCard, const std::string& owner)
    : id(cardId), cardType(type), expiryDate(expiry), cvc(cvcCode), balance(initialBalance), password(passwordCard), ownerName(owner) {}

std::string Card::getId() const { return id; }
int Card::getPassword() const { return password; }
std::string Card::getCardType() const { return cardType; }
std::string Card::getExpiryDate() const { return expiryDate; }
std::string Card::getCvc() const { return cvc; }
double Card::getBalance() const { return balance; }
void Card::setBalance(double newBalance) { balance = newBalance; }
std::string Card::getOwnerName() const { return ownerName; }

bool Card::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient funds on the card.\n";
        return false;
    }
    balance -= amount;
    std::cout << "Withdrawal successful. Remaining balance: " << balance << " RUB.\n";
    return true;
}

void Card::deposit(double amount) {
    balance += amount;
    std::cout << "Deposit successful. Current balance: " << balance << " RUB.\n";
}

void Card::displayCardDetails() const {
    std::cout << "Card ID: " << id
              << "\nCard Number: " << cardType
              << "\nExpiry Date: " << expiryDate
              << "\nCVC Code: " << cvc
              << "\nBalance: " << balance << "RUB"
              << "\nOwner: " << ownerName << "\n";
}


