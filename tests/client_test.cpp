#include "gtest/gtest.h"
#include "../include/client.h"
#include "../include/card.h"
#include "../include/account .h"
#include "../include/transaction.h"
#include "../include/credit.h"

class ClientTest : public ::testing::Test {
protected:
    Card card1{"123", "Debit", "12/25", "123", 5000.0, 1234, "Sender"};
    Card card2{"456", "Credit", "12/24", "456", 3000.0, 5678, "Sender"};
    Account account1{"acc1"};
    Account account2{"acc2"};
    Client sender{"Sender", 30, 10000.0, 5000.0, 2000.0};
    Client receiver{"Receiver", 25, 5000.0, 3000.0, 1000.0};

    ClientTest() {
        sender.addCard(card1);
        sender.addCard(card2);
        sender.addAccount(account1);

        receiver.addCard(Card{"789", "Debit", "11/24", "789", 2000.0, 1111, "Receiver"});
        receiver.addAccount(account2);
    }
};

TEST_F(ClientTest, AddCardTest) {
    Card newCard{"111", "Debit", "12/26", "789", 4000.0, 1234, "Sender"};
    sender.addCard(newCard);
    EXPECT_EQ(sender.getCashRub(), 10000.0);
    EXPECT_EQ(sender.getTotalBalance(), 22000.0);
}


TEST_F(ClientTest, RemoveCardTest) {
    sender.removeCard("123");
    EXPECT_EQ(sender.getCashRub(), 10000.0);
    EXPECT_EQ(sender.getTotalBalance(), 13000.0);
}

TEST_F(ClientTest, CreateTransactionSuccessTest) {
    bool result = sender.createTransaction(receiver, "123", "789", 2000.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(sender.getCashRub(), 10000.0);
    EXPECT_EQ(receiver.getCashRub(), 5000.0);
}

TEST_F(ClientTest, CreateTransactionInsufficientFundsTest) {
    bool result = sender.createTransaction(receiver, "123", "789", 6000.0);  // На карте отправителя недостаточно средств
    EXPECT_FALSE(result);
    EXPECT_EQ(sender.getCashRub(), 10000.0);
    EXPECT_EQ(receiver.getCashRub(), 5000.0);
}

TEST_F(ClientTest, CreateTransactionCardNotFoundTest) {
    bool result = sender.createTransaction(receiver, "nonexistent", "789", 2000.0);
    EXPECT_FALSE(result);
}


TEST_F(ClientTest, AddAccountTest) {
    Account newAccount{"acc3"};
    sender.addAccount(newAccount);
    EXPECT_EQ(sender.getTotalBalance(), 18000.0);
}

TEST_F(ClientTest, RemoveAccountTest) {
    sender.removeAccount("acc1");
    EXPECT_EQ(sender.getTotalBalance(), 18000.0);
}

TEST_F(ClientTest, DisplayClientDetailsTest) {
    testing::internal::CaptureStdout();
    sender.displayClientDetails();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Sender"), std::string::npos);
    EXPECT_NE(output.find("Cash in Rubles: 10000"), std::string::npos);
    EXPECT_NE(output.find("Linked Cards"), std::string::npos);
}

