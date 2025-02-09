#include <gtest/gtest.h>
#include "../include/account .h"
#include "../include/card.h"

class AccountTest : public ::testing::Test {
protected:
    Account account;
    Card card1;
    Card card2;

    AccountTest()
        : account("ACC12345"),
          card1("1234-5678-9876-5432", "Debit", "12/25", "123", 1000.0, 1234, "John Doe"),
          card2("2345-6789-8765-4321", "Credit", "11/26", "124", 2000.0, 5678, "Jane Doe") {}
};

TEST_F(AccountTest, ConstructorAndGettersTest) {
    EXPECT_EQ(account.getId(), "ACC12345");
    EXPECT_EQ(account.getBalance(), 0.0);
}

TEST_F(AccountTest, AddCardTest) {
    account.addCard(card1);
    EXPECT_EQ(account.getBalance(), 1000.0);

    account.addCard(card2);
    EXPECT_EQ(account.getBalance(), 3000.0);
}

TEST_F(AccountTest, RemoveCardTest) {
    account.addCard(card1);
    account.addCard(card2);

    account.removeCard(card1.getId());
    EXPECT_EQ(account.getBalance(), 2000.0);

    account.removeCard(card1.getId());
    EXPECT_EQ(account.getBalance(), 2000.0);
}

TEST_F(AccountTest, DisplayAccountDetailsTest) {
    testing::internal::CaptureStdout();
    account.addCard(card1);
    account.addCard(card2);
    account.displayAccountDetails();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Account ID: ACC12345"), std::string::npos);
    EXPECT_NE(output.find("Linked Cards:"), std::string::npos);
    EXPECT_NE(output.find("Card ID: 1234-5678-9876-5432"), std::string::npos);
    EXPECT_NE(output.find("Balance: 1000"), std::string::npos);
    EXPECT_NE(output.find("Card ID: 2345-6789-8765-4321"), std::string::npos);
    EXPECT_NE(output.find("Balance: 2000"), std::string::npos);
    EXPECT_NE(output.find("Total Account Balance: 3000"), std::string::npos);
}
