
#include "../include/credit.h"
#include "../include/client.h"  // Подключаем client.h для полной информации о классе Client
#include <cmath>  // Для вычислений процентов


Credit::Credit(const std::string& creditId, double principal, double rate, int term, Client* clientPtr)
    : id(creditId),
      principalAmount(principal),
      interestRate(rate),
      termMonths(term),
      isActive(true),
      client(clientPtr) {
    calculateMonthlyPayment();
}


void Credit::calculateMonthlyPayment() {
    if (termMonths == 0 || interestRate < 0) {
        monthlyPayment = 0.0;
        return;
    }

    double monthlyRate = interestRate / 12 / 100;
    monthlyPayment = (principalAmount * monthlyRate) / (1 - std::pow(1 + monthlyRate, -termMonths));
}


std::string Credit::getId() const { return id; }
double Credit::getPrincipalAmount() const { return principalAmount; }
double Credit::getInterestRate() const { return interestRate; }
int Credit::getTermMonths() const { return termMonths; }
double Credit::getMonthlyPayment() const { return monthlyPayment; }
bool Credit::getIsActive() const { return isActive; }
Client* Credit::getClient() const { return client; }


void Credit::makePayment(double amount) {
    if (!isActive) {
        std::cout << "Credit is already paid off.\n";
        return;
    }

    if (amount >= principalAmount) {
        principalAmount = 0.0;
        isActive = false;
        std::cout << "Credit with ID: " << id << " has been fully paid off.\n";
    } else {
        principalAmount -= amount;
        std::cout << "Payment of " << amount << " made. Remaining principal: " << principalAmount << "\n";
        calculateMonthlyPayment();
    }
}


void Credit::displayCreditDetails() const {
    std::cout << "Credit Details:\n"
              << "ID: " << id << "\n"
              << "Principal Amount: " << principalAmount << " RUB\n"
              << "Interest Rate: " << interestRate << "%\n"
              << "Term: " << termMonths << " months\n"
              << "Monthly Payment: " << monthlyPayment << " RUB\n"
              << "Status: " << (isActive ? "Active" : "Paid Off") << "\n"
              << "Client: " << (client ? client->getName() : "No client assigned") << "\n";
}
