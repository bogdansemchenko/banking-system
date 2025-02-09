#include "./include/bank.h"
#include "./include/employee.h"
#include "./include/client.h"
#include "./include/card.h"
#include "./include/database.h"
#include "./include/atm.h"
#include "./include/currencyExchange.h"
#include <iostream>
#include "./include/thiefgang.h"
#include <regex>

void displayMainMenu() {
    std::cout << "\n=== Main Menu ===\n";
    std::cout << "1. View bank details\n";
    std::cout << "2. View client #2 details\n";
    std::cout << "3. Log in as client #1\n";
    std::cout << "4. View bank database details\n";
    std::cout << "5. View currency exchange rates\n";
    std::cout << "6. Log in as thieves\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}


void displayClientMenu() {
    std::cout << "\n=== Client Menu ===\n";
    std::cout << "1. View my details\n";
    std::cout << "2. Perform a transaction\n";
    std::cout << "3. Create a card (via employee)\n";
    std::cout << "4. Apply for a loan (via employee)\n";
    std::cout << "5. Exchange currency (via employee)\n";
    std::cout << "6. Withdraw money from an ATM\n";
    std::cout << "7. Deposit money into an ATM\n";
    std::cout << "8. View my transactions\n";
    std::cout << "9. View my loans\n";
    std::cout << "0. Return to main menu\n";
    std::cout << "Enter your choice: ";
}


void displayThiefMenu() {
    std::cout << "\n=== Thief Menu ===\n";
    std::cout << "1. View gang details\n";
    std::cout << "2. Increase gang skill\n";
    std::cout << "3. Increase gang size\n";
    std::cout << "4. Attempt bank robbery\n";
    std::cout << "0. Return to main menu\n";
    std::cout << "Enter your choice: ";
}


int getIntInput(const std::string& prompt) {
    int value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Check if the input contains only digits (positive integers)
        std::regex intRegex("^\\d+$");
        if (std::regex_match(input, intRegex)) {
            try {
                value = std::stoi(input); // Convert the string to an integer
                return value;
            } catch (std::out_of_range&) {
                std::cout << "The entered number is too large. Please try again.\n";
            }
        } else {
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
    }
}

double getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        // Проверка, чтобы ввод содержал только цифры или точку (для чисел с плавающей точкой)
        std::regex doubleRegex("^\\d*\\.?\\d+$");  // Регулярное выражение для чисел с плавающей точкой
        if (std::regex_match(input, doubleRegex)) {
            try {
                value = std::stod(input);  // Преобразуем строку в число с плавающей точкой
                // Проверка на положительность числа
                if (value <= 0) {
                    std::cout << "The number must be positive. Please try again.\n";
                } else {
                    return value;
                }
            } catch (const std::invalid_argument&) {
                std::cout << "Invalid input. Please enter a valid number.\n";
            }
        } else {
            std::cout << "Invalid input. Please enter a valid number without any operators.\n";
        }
    }
}
std::string getStringInput(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Check if the input contains only letters (both cases) and spaces
        std::regex alphaRegex("^[A-Za-zА-Яа-яЁё ]+$"); // Supports Latin and Cyrillic letters
        if (std::regex_match(input, alphaRegex)) {
            return input; // Valid input
        } else {
            std::cout << "Invalid input. Please enter letters only (no numbers or special characters).\n";
        }
    }
}

std::string getValidatedCardNumber(const std::string& prompt) {
    std::string cardNumber;
    std::regex cardRegex("^\\d{4}-\\d{4}-\\d{4}-\\d{4}$"); // Regex for card number format

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, cardNumber);

        if (std::regex_match(cardNumber, cardRegex)) {
            return cardNumber; // Valid card number
        } else {
            std::cout << "Invalid card number. Please enter in the format XXXX-XXXX-XXXX-XXXX.\n";
        }
    }
}
std::string getValidatedExpiryDate(const std::string& prompt) {
    std::string expiryDate;
    std::regex dateRegex("^\\d{2}/\\d{2}$"); // Regex for MM/YY format

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, expiryDate);

        if (std::regex_match(expiryDate, dateRegex)) {
            int month = std::stoi(expiryDate.substr(0, 2));
            int year = std::stoi(expiryDate.substr(3, 2));

            // Check if the month is valid and year is in the range 25-30
            if (month >= 1 && month <= 12 && year >= 25 && year <= 30) {
                return expiryDate; // Valid expiry date
            } else {
                std::cout << "Invalid expiry date. Please ensure the month is between 01 and 12 and the year is between 25 and 30.\n";
            }
        } else {
            std::cout << "Invalid format. Please enter the expiry date in the format MM/YY.\n";
        }
    }
}

std::string getValidatedCVC(const std::string& prompt) {
    std::string cvc;
    std::regex cvcRegex("^\\d{3}$"); // Regex for 3-digit CVC code

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, cvc);

        if (std::regex_match(cvc, cvcRegex)) {
            return cvc; // Valid CVC code
        } else {
            std::cout << "Invalid CVC. Please enter exactly 3 digits.\n";
        }
    }
}

// Function to validate card password
int getValidatedPassword(const std::string& prompt) {
    std::string passwordInput;
    std::regex passwordRegex("^\\d{4}$"); // Regex for 4-digit password

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, passwordInput);

        if (std::regex_match(passwordInput, passwordRegex)) {
            try {
                return std::stoi(passwordInput); // Convert to integer
            } catch (std::out_of_range&) {
                std::cout << "Password number is too large. Please try again.\n";
            }
        } else {
            std::cout << "Invalid password. Please enter exactly 4 digits.\n";
        }
    }
}

std::string getValidatedLoanID(const std::string& prompt) {
    std::string loanID;
    std::regex loanIDRegex("^\\d{8}$"); // Regex for exactly 8 digits

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, loanID);

        if (std::regex_match(loanID, loanIDRegex)) {
            return loanID; // Valid loan ID
        } else {
            std::cout << "Invalid loan ID. Please enter exactly 8 digits.\n";
        }
    }
}

int main() {
    Bank bank("BibiBank", "Oleg Ivanov", 1991, 1000000000.0, 4.7, 2000000000.0, 5);
    Database& bankDatabase = bank.getDatabase();
    CurrencyExchange& exchangeRates = bank.getExchangeRates();
    ATM atm(50000.0, "ATM12345");
    Employee employee1("John Doe", 30, bank);
    Employee employee2("Jane Smith", 28, bank);
    Client client1("Alexey Sokolov", 25, 10000, 500, 2000);
    Client client2("Maria Petrova", 32, 15000, 1000, 3000);
    bankDatabase.addClient(client1);
    bankDatabase.addClient(client2);
    Card card1("1234-5678-9876-5432", "Visa", "12/26", "123", 5000.0, 1234, client1.getName());
    Card card2("4321-8765-4321-8765", "Visa", "10/27", "789", 7000.0, 9101, client2.getName());
    client1.addCard(card1);
    client2.addCard(card2);

    ThiefGang thieves("The Black Cats", 3, 5);

    int choice;
    do {
        displayMainMenu();
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: {
                bank.displayBankInfo();
                break;
            }
            case 2: {
                client2.displayClientDetails();
                break;
            }
            case 3: {
                int clientChoice;
                do {
                    displayClientMenu();
                    clientChoice = getIntInput("Enter your choice: ");

                    switch (clientChoice) {
                        case 1: {
                            client1.displayClientDetails();
                            break;
                        }
                        case 2: {
                            std::string senderCardId = getValidatedCardNumber("Enter sender card ID: ");
                            Card* senderCard = client1.findCardById(senderCardId);
                            if (!senderCard) {
                                std::cout << "Sender card not found.\n";
                                break;
                            }

                            std::string receiverCardId = getValidatedCardNumber("Enter receiver card ID: ");
                            double amount = getDoubleInput("Enter amount: ");

                            if (client1.createTransaction(client2, senderCardId, receiverCardId, amount)) {
                                std::cout << "Transaction successful.\n";
                            } else {
                                std::cout << "Transaction failed.\n";
                            }
                            break;
                        }
                        case 3: {
                            std::string cardId = getValidatedCardNumber("Enter card ID: ");
                            std::string cardType = getStringInput("Enter card type: ");
                            std::string expiryDate = getValidatedExpiryDate("Enter expiry date (MM/YY): ");
                            std::string cvc = getValidatedCVC("Enter CVC: ");
                            int password = getValidatedPassword("Enter card password: ");

                            employee1.createCardForClient(client1, cardId, cardType, expiryDate, cvc, 0, password, client1.getName());
                            std::cout << "Card created successfully.\n";
                            break;
                        }
                        case 4: {
                            std::string creditId = getValidatedLoanID("Enter loan ID: ");
                            double principal = getDoubleInput("Enter loan amount: ");
                            double rate = getDoubleInput("Enter interest rate: ");
                            int term = getIntInput("Enter loan term (in months): ");

                            employee1.createCreditForClient(client1, creditId, principal, rate, term);
                            std::cout << "Loan successfully issued.\n";
                            break;
                        }
                        case 5: {
                            double amount = getDoubleInput("Enter amount: ");
                            std::string fromCurrency = getStringInput("Enter source currency (RUB/USD/EUR): ");
                            std::string toCurrency = getStringInput("Enter target currency (RUB/USD/EUR): ");

                            employee1.exchangeCurrency(client1, amount, fromCurrency, toCurrency);
                            std::cout << "Currency exchange completed.\n";
                            break;
                        }
                        case 6: {
                            std::string cardId = getValidatedCardNumber("Enter card ID: ");
                            Card* card = client1.findCardById(cardId);
                            if (!card) {
                                std::cout << "Card not found.\n";
                                break;
                            }

                            double amount = getDoubleInput("Enter amount: ");
                            int password = getValidatedPassword("Enter password: ");
                            atm.withdrawMoney(client1, *card, amount, password);
                            break;
                        }
                        case 7: {
                            std::string cardId = getValidatedCardNumber("Enter card ID: ");
                            Card* card = client1.findCardById(cardId);
                            if (!card) {
                                std::cout << "Card not found.\n";
                                break;
                            }

                            double amount = getDoubleInput("Enter amount: ");
                            int password = getValidatedPassword("Enter password: ");
                            atm.depositMoney(client1, *card, amount, password);
                            break;
                        }
                        case 8: {
                            client1.displayTransactions();
                            break;
                        }
                        case 9: {
                            client1.displayCredits();
                            break;
                        }
                        case 0: {
                            std::cout << "Returning to main menu.\n";
                            break;
                        }
                        default:
                            std::cout << "Invalid choice. Try again.\n";
                    }
                } while (clientChoice != 0);
                break;
            }
            case 4: {
                bankDatabase.displayClients();
                bankDatabase.displayCards();
                bankDatabase.displayCredits();
                break;
            }
            case 5: {
                exchangeRates.displayExchangeRates();
                break;
            }
            case 6: {
                int thiefChoice;
                do {
                    displayThiefMenu();
                    thiefChoice = getIntInput("Enter your choice: ");

                    switch (thiefChoice) {
                        case 1: {
                            thieves.displayGangInfo();
                            break;
                        }
                        case 2: {
                            thieves.increaseSkillRating();
                            break;
                        }
                        case 3: {
                            thieves.addMember();
                            break;
                        }
                        case 4: {
                            if (thieves.attemptBankRobbery(bank)) {
                                std::cout << "The gang successfully robbed the bank!\n";
                            } else {
                                std::cout << "The robbery attempt failed.\n";
                            }
                            break;
                        }
                        case 0: {
                            std::cout << "Returning to main menu.\n";
                            break;
                        }
                        default:
                            std::cout << "Invalid choice. Try again.\n";
                    }
                } while (thiefChoice != 0);
                break;
            }
            case 0: {
                std::cout << "Exiting.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

