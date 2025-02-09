#pragma once

#include <string>
#include <chrono>
#include "card.h"

class Transaction {
private:
    Card senderCard;
    Card receiverCard;
    double amount;
    std::chrono::system_clock::time_point transactionTime;
    double commission;
    std::string message;

public:
    Transaction(const Card& sender, const Card& receiver, double amount, const std::string& message = "No message");

    [[nodiscard]] Card getSenderCard() const;
    [[nodiscard]] Card getReceiverCard() const;
    [[nodiscard]] std::string getReceiverCardId() const;
    [[nodiscard]] std::string getSenderCardId() const;
    [[nodiscard]] double getAmount() const;
    [[nodiscard]] std::string getTransactionTime() const;
    [[nodiscard]] double getCommission() const;
    [[nodiscard]] std::string getMessage() const;

    void displayTransactionDetails() const;
};
