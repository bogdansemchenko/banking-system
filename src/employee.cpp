#include "../include/employee.h"
#include <iostream>

Employee::Employee(const std::string& name, int age, Bank& bank)
    : Person(name, age), bank(bank) {}

void Employee::createCardForClient(Client& client, const std::string& cardId, const std::string& cardType, const std::string& expiryDate, const std::string& cvc, double initialBalance, int password, const std::string& owner) {
    Card newCard(cardId, cardType, expiryDate, cvc, initialBalance, password, owner);
    client.addCard(newCard);
    bank.getDatabase().addCard(newCard);
    bank.getDatabase().addClient(client);
    std::cout << "New card created for " << owner << " with ID: " << cardId << "\n";
}

void Employee::exchangeCurrency(Client& client, double amount, const std::string& fromCurrency, const std::string& toCurrency) {
    CurrencyExchange exchange;

    if (fromCurrency == "RUB" && toCurrency == "USD") {
        double usdAmount = exchange.convertRubToUsd(amount);
        client.setCashUsd(client.getCashUsd() + usdAmount);
        client.setCashRub(client.getCashRub() - amount);
        std::cout << "Exchanged " << amount << " RUB to " << usdAmount << " USD\n";
    }
    else if (fromCurrency == "RUB" && toCurrency == "EUR") {
        double eurAmount = exchange.convertRubToEur(amount);
        client.setCashEur(client.getCashEur() + eurAmount);
        client.setCashRub(client.getCashRub() - amount);
        std::cout << "Exchanged " << amount << " RUB to " << eurAmount << " EUR\n";
    }
    else if (fromCurrency == "USD" && toCurrency == "RUB") {
        double rubAmount = exchange.convertUsdToRub(amount);
        client.setCashRub(client.getCashRub() + rubAmount);
        client.setCashUsd(client.getCashUsd() - amount);
        std::cout << "Exchanged " << amount << " USD to " << rubAmount << " RUB\n";
    }
    else if (fromCurrency == "EUR" && toCurrency == "RUB") {
        double rubAmount = exchange.convertEurToRub(amount);
        client.setCashRub(client.getCashRub() + rubAmount);
        client.setCashEur(client.getCashEur() - amount);
        std::cout << "Exchanged " << amount << " EUR to " << rubAmount << " RUB\n";
    }
    else {
        std::cout << "Currency exchange not supported for this combination.\n";
    }
}

void Employee::createCreditForClient(Client& client, const std::string& creditId, double principal, double rate, int term) {
    if (bank.getBankBudget() >= principal) {
        Credit newCredit(creditId, principal, rate, term, &client);
        client.addCredit(newCredit);
        bank.getDatabase().addCredit(newCredit);
        client.setCashRub(client.getCashRub() + principal);
        bank.updateBankBudget(-principal);
        std::cout << "New credit created for client " << client.getName() << " with ID: " << creditId << "\n";
        std::cout << "Amount of credit (" << principal << " RUB) added to the client's balance.\n";
        std::cout << "Bank's new budget: " << bank.getBankBudget() << " RUB\n";
    } else {
        std::cout << "Insufficient bank budget for this credit request.\n";
    }
}


