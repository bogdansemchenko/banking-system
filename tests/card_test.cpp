#include <gtest/gtest.h>
#include "../include/card.h"

class CardTest : public ::testing::Test {
protected:
    Card card;

    CardTest()
        : card("1234-5678-9876-5432", "Debit", "12/25", "123", 1000.0, 1234, "John Doe") {}
};

TEST_F(CardTest, ConstructorAndGettersTest) {
    EXPECT_EQ(card.getId(), "1234-5678-9876-5432");
    EXPECT_EQ(card.getCardType(), "Debit");
    EXPECT_EQ(card.getExpiryDate(), "12/25");
    EXPECT_EQ(card.getCvc(), "123");
    EXPECT_EQ(card.getBalance(), 1000.0);
    EXPECT_EQ(card.getPassword(), 1234);
    EXPECT_EQ(card.getOwnerName(), "John Doe");
}

TEST_F(CardTest, DepositTest) {
    card.deposit(500.0);
    EXPECT_EQ(card.getBalance(), 1500.0);

    card.deposit(200.0);
    EXPECT_EQ(card.getBalance(), 1700.0);
}

TEST_F(CardTest, WithdrawTest) {
    EXPECT_TRUE(card.withdraw(200.0));
    EXPECT_EQ(card.getBalance(), 800.0);

    EXPECT_FALSE(card.withdraw(2000.0));
    EXPECT_EQ(card.getBalance(), 800.0);
}

TEST_F(CardTest, WithdrawEdgeTest) {
    EXPECT_TRUE(card.withdraw(1000.0));
    EXPECT_EQ(card.getBalance(), 0.0);

    EXPECT_FALSE(card.withdraw(1.0));
    EXPECT_EQ(card.getBalance(), 0.0);
}

TEST_F(CardTest, DisplayCardDetailsTest) {
    testing::internal::CaptureStdout();
    card.displayCardDetails();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Card ID: 1234-5678-9876-5432"), std::string::npos);
    EXPECT_NE(output.find("Card Number: Debit"), std::string::npos);
    EXPECT_NE(output.find("Expiry Date: 12/25"), std::string::npos);
    EXPECT_NE(output.find("CVC Code: 123"), std::string::npos);
    EXPECT_NE(output.find("Balance: 1000RUB"), std::string::npos);
    EXPECT_NE(output.find("Owner: John Doe"), std::string::npos);
}
