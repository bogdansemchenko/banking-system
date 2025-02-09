#include "gtest/gtest.h"
#include "../include/bank.h"

class BankTest : public ::testing::Test {
protected:
    Bank bank{"TestBank", "TestOwner", 1999, 1000000.0, 8.5, 5000000.0, 7};
    BankTest() = default;
};

TEST_F(BankTest, ConstructorAndGettersTest) {
    EXPECT_EQ(bank.getBankName(), "TestBank");
    EXPECT_EQ(bank.getOwnerName(), "TestOwner");
    EXPECT_EQ(bank.getYearEstablished(), 1999);
    EXPECT_EQ(bank.getBankBudget(), 1000000.0);
    EXPECT_EQ(bank.getBankRating(), 8.5);
    EXPECT_EQ(bank.getBankValue(), 5000000.0);
    EXPECT_EQ(bank.getSafetyCoefficient(), 7);
}

TEST_F(BankTest, UpdateBankBudgetTest) {
    bank.updateBankBudget(50000.0);
    EXPECT_EQ(bank.getBankBudget(), 1050000.0);
    bank.updateBankBudget(-200000.0);
    EXPECT_EQ(bank.getBankBudget(), 850000.0);
}

TEST_F(BankTest, SetBankBudgetTest) {
    bank.setBankBudget(2000000.0);
    EXPECT_EQ(bank.getBankBudget(), 2000000.0);
}
TEST_F(BankTest, UpdateBankValueTest) {
    bank.updateBankValue(1000000.0);
    EXPECT_EQ(bank.getBankValue(), 6000000.0);

    bank.updateBankValue(-500000.0);
    EXPECT_EQ(bank.getBankValue(), 5500000.0);
}


TEST_F(BankTest, UpdateSafetyCoefficientTest) {
    bank.updateSafetyCoefficient(8);
    EXPECT_EQ(bank.getSafetyCoefficient(), 8);
    bank.updateSafetyCoefficient(0);
    EXPECT_EQ(bank.getSafetyCoefficient(), 1);
    bank.updateSafetyCoefficient(15);
    EXPECT_EQ(bank.getSafetyCoefficient(), 10);
}

// Тест для базы данных и курсов валют
TEST_F(BankTest, DatabaseAndExchangeRatesTest) {
    EXPECT_NO_THROW(bank.getDatabase());
    EXPECT_NO_THROW(bank.getExchangeRates());
}
