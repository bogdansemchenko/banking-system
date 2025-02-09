#include "gtest/gtest.h"
#include "../include/database.h"
#include "../include/client.h"
#include "../include/card.h"
#include "../include/credit.h"

Client client1("Alice", 23, 2000, 12121, 2121 );
Client client2("Bob", 44, 323232, 23232, 2323232);
Card card1("1234567890", "Debit", "12/25", "123", 5000.0, 1111, client1.getName());
Card card2("0987654321", "Credit", "11/24", "456", 10000.0, 2222, client2.getName());
Credit credit1("CR001", 50000.0, 10.5, 12, &client1);
Credit credit2("CR002", 30000.0, 9.0, 24, &client2);




TEST(DatabaseTest, ClientExistsTest) {
    Database db;

    db.addClient(client1);

    EXPECT_TRUE(db.clientExists("Alice"));  // Клиент должен существовать
    EXPECT_FALSE(db.clientExists("Charlie"));  // Клиент с таким именем не существует
}

TEST(DatabaseTest, AddCardTest) {
    Database db;

    db.addCard(card1);
    db.addCard(card2);

    testing::internal::CaptureStdout();
    db.displayCards();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1234567890"), std::string::npos);
    EXPECT_NE(output.find("0987654321"), std::string::npos);
}

TEST(DatabaseTest, AddCreditTest) {
    Database db;

    db.addCredit(credit1);
    db.addCredit(credit2);

    testing::internal::CaptureStdout();
    db.displayCredits();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("CR001"), std::string::npos);
    EXPECT_NE(output.find("CR002"), std::string::npos);
}

TEST(DatabaseTest, DisplayDatabaseTest) {
    Database db;

    db.addClient(client1);
    db.addClient(client2);
    db.addCard(card1);
    db.addCard(card2);
    db.addCredit(credit1);
    db.addCredit(credit2);

    testing::internal::CaptureStdout();
    db.displayClients();
    std::string outputClients = testing::internal::GetCapturedStdout();
    EXPECT_NE(outputClients.find("Alice"), std::string::npos);
    EXPECT_NE(outputClients.find("Bob"), std::string::npos);

    testing::internal::CaptureStdout();
    db.displayCards();
    std::string outputCards = testing::internal::GetCapturedStdout();
    EXPECT_NE(outputCards.find("1234567890"), std::string::npos);
    EXPECT_NE(outputCards.find("0987654321"), std::string::npos);

    testing::internal::CaptureStdout();
    db.displayCredits();
    std::string outputCredits = testing::internal::GetCapturedStdout();
    EXPECT_NE(outputCredits.find("CR001"), std::string::npos);
    EXPECT_NE(outputCredits.find("CR002"), std::string::npos);
}
