#include "../include/transaction.h"
#include <iostream>
#include <iomanip>  // Для форматирования времени
#include <chrono>

Transaction::Transaction(const Card& sender, const Card& receiver, double amount, const std::string& message)
    : senderCard(sender), receiverCard(receiver), amount(amount), commission(0.0), message(message) {
    // Время транзакции автоматически устанавливается на текущее время
    transactionTime = std::chrono::system_clock::now();
}

Card Transaction::getSenderCard() const {
    return senderCard;
}
std::string Transaction::getReceiverCardId() const {
    return receiverCard.getId();
}
std::string Transaction::getSenderCardId() const {
    return senderCard.getId();
}

Card Transaction::getReceiverCard() const {
    return receiverCard;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTransactionTime() const {
    // Конвертируем время транзакции в строку
    std::time_t time = std::chrono::system_clock::to_time_t(transactionTime);
    std::tm* timeInfo = std::localtime(&time);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    return std::string(buffer);
}

double Transaction::getCommission() const {
    return commission;
}

std::string Transaction::getMessage() const {
    return message;
}

void Transaction::displayTransactionDetails() const {
    std::cout << "Transaction Details:\n"
              << "Sender Card ID: " << senderCard.getId() << "\n"
              << "Receiver Card ID: " << receiverCard.getId() << "\n"
              << "Amount: " << amount << " RUB\n"
              << "Transaction Time: " << getTransactionTime() << "\n"
              << "Commission: " << commission << " RUB\n"
              << "Message: " << message << "\n";
}
