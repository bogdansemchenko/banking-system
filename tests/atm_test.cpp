#include <gtest/gtest.h>
#include "../include/atm.h"
#include "../include/card.h"
#include "../include/client.h"

class ATMTest : public ::testing::Test {
protected:
    Client client;
    Card card;
    ATM atm;
    ATMTest()
        : client("John Doe", 30, 10000.0, 1000.0, 800.0),
          card("1234-5678-9876-5432", "Debit", "12/25", "123", 5000.0, 1234, "John Doe"),  // Карта с 5000 руб.
          atm(20000.0, "ATM123") {}  // Банкомат с балансом 20000 руб.
};

TEST_F(ATMTest, ConstructorTest) {
    testing::internal::CaptureStdout();
    atm.displayATMBalance();
    atm.displayATMSN();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("ATM balance: 20000 RUB"), std::string::npos);
    EXPECT_NE(output.find("ATM Serial Number: ATM123"), std::string::npos);
}

TEST_F(ATMTest, WithdrawMoneyTest) {
    atm.withdrawMoney(client, card, 3000.0, 1234);

    EXPECT_EQ(card.getBalance(), 2000.0);
    EXPECT_EQ(client.getCashRub(), 13000.0);

}

TEST_F(ATMTest, InsufficientFundsOnCardTest) {
    testing::internal::CaptureStdout();
    atm.withdrawMoney(client, card, 6000.0, 1234);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Insufficient funds on the card."), std::string::npos);
}


TEST_F(ATMTest, DepositMoneyTest) {
    atm.depositMoney(client, card, 1000.0, 1234);

    EXPECT_EQ(client.getCashRub(), 9000.0);
    EXPECT_EQ(card.getBalance(), 6000.0);
}

TEST_F(ATMTest, InsufficientFundsForDepositTest) {
    testing::internal::CaptureStdout();
    atm.depositMoney(client, card, 20000.0, 1234);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Insufficient funds in your cash balance."), std::string::npos);
}

TEST_F(ATMTest, DisplayCardBalanceTest) {
    testing::internal::CaptureStdout();
    atm.displayCardBalance(card);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Card ID: 1234-5678-9876-5432"), std::string::npos);
    EXPECT_NE(output.find("Card Balance: 5000"), std::string::npos);
}
