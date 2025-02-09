#include "../include/atm.h"

ATM::ATM(double initialBalance, const std::string& serial)
    : atmBalanceRub(initialBalance), serialNumber(serial) {}

void ATM::withdrawMoney(Client &client, Card &card, double amount, int enteredPassword) {
    if (enteredPassword != card.getPassword()) {
        std::cout << "Incorrect password. Withdrawal failed.\n";
        return;
    }
    if (card.getBalance() >= amount && atmBalanceRub >= amount) {
        card.withdraw(amount);
        client.setCashRub(client.getCashRub() + amount);
        atmBalanceRub -= amount;

        std::cout << "Withdrawal successful. " << amount << " RUB added to your cash balance.\n";
    } else {
        if (card.getBalance() < amount) {
            std::cout << "Insufficient funds on the card.\n";
        } else if (atmBalanceRub < amount) {
            std::cout << "ATM does not have enough funds.\n";
        }
    }
}

void ATM::depositMoney(Client &client, Card &card, double amount, int enteredPassword) {
    if (enteredPassword != card.getPassword()) {
        std::cout << "Incorrect password. Deposit failed.\n";
        return;
    }
    if (client.getCashRub() >= amount) {
        client.setCashRub(client.getCashRub() - amount);
        card.deposit(amount);

        std::cout << "Deposit successful. " << amount << " RUB deposited to the card.\n";
    } else {
        std::cout << "Insufficient funds in your cash balance.\n";
    }
}

void ATM::displayATMBalance() const {
    std::cout << "ATM balance: " << atmBalanceRub << " RUB.\n";
}

void ATM::displayATMSN() const {
    std::cout << "ATM Serial Number: " << serialNumber << "\n";
}
void ATM::displayCardBalance(const Card &card) const {
    std::cout << "Card ID: " << card.getId()
              << "\nCard Balance: " << card.getBalance() << " RUB\n";
}

