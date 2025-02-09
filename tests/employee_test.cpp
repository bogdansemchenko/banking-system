#include "gtest/gtest.h"
#include "../include/employee.h"
#include "../include/client.h"
#include "../include/card.h"
#include "../include/credit.h"
#include "../include/bank.h"
#include "../include/currencyExchange.h"


class EmployeeTest : public ::testing::Test {
protected:

    Bank bank{"National Bank", "John Smith", 2000, 1000000.0, 4.5, 2000000.0};
    Employee employee{"Alice", 35, bank};
    Client sender{"Sender", 30, 10000.0, 5000.0, 2000.0};
    Client receiver{"Receiver", 25, 5000.0, 3000.0, 1000.0};

    Card card1{"123", "Debit", "12/25", "123", 5000.0, 1234, "Sender"};
    Card card2{"456", "Credit", "12/24", "456", 3000.0, 5678, "Sender"};

    EmployeeTest() {
        sender.addCard(card1);
        sender.addCard(card2);
        bank.getDatabase().addClient(sender);
    }
};


TEST_F(EmployeeTest, CreateCardForClientTest) {

    EXPECT_EQ(sender.getCashRub(), 10000.0);
    EXPECT_EQ(sender.getTotalBalance(), 18000.0);

    // Сотрудник создает карту для клиента
    employee.createCardForClient(sender, "789", "Debit", "12/26", "789", 4000.0, 1234, "Sender");

    EXPECT_EQ(sender.getTotalBalance(), 22000.0);
}

TEST_F(EmployeeTest, ExchangeCurrencyTest) {
    double initialRUB = sender.getCashRub();
    double initialUSD = sender.getCashUsd();
    EXPECT_EQ(initialRUB, 10000.0);
    EXPECT_EQ(initialUSD, 5000.0);
    employee.exchangeCurrency(sender, 2000.0, "RUB", "USD");
    EXPECT_EQ(sender.getCashRub(), initialRUB - 2000.0);
    EXPECT_GT(sender.getCashUsd(), initialUSD);
}
TEST_F(EmployeeTest, CreateCreditForClientTest) {
    double initialBankBudget = bank.getBankBudget();
    double initialSenderBalance = sender.getCashRub();
    EXPECT_EQ(initialSenderBalance, 10000.0);
    EXPECT_EQ(initialBankBudget, 1000000.0);

    employee.createCreditForClient(sender, "CREDIT001", 5000.0, 7.5, 12);

    EXPECT_EQ(sender.getCashRub(), initialSenderBalance + 5000.0);
    EXPECT_EQ(bank.getBankBudget(), initialBankBudget - 5000.0);
}


TEST_F(EmployeeTest, CreateCreditInsufficientBankBudgetTest) {
    bank.updateBankBudget(-999995.0);

    double initialSenderBalance = sender.getCashRub();
    double initialBankBudget = bank.getBankBudget();
    EXPECT_EQ(initialSenderBalance, 10000.0);
    EXPECT_EQ(initialBankBudget, 5.0);

    employee.createCreditForClient(sender, "CREDIT001", 5000.0, 7.5, 12);
    EXPECT_EQ(sender.getCashRub(), initialSenderBalance);
    EXPECT_EQ(bank.getBankBudget(), initialBankBudget);
}


