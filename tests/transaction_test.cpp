#include "gtest/gtest.h"
#include "../include/transaction.h"
#include "../include/card.h"


class TransactionTest : public ::testing::Test {
protected:
    Card senderCard{"123", "Debit", "12/25", "123", 5000.0, 1234, "Sender"};
    Card receiverCard{"456", "Credit", "12/24", "456", 3000.0, 5678, "Receiver"};
    Transaction transaction{senderCard, receiverCard, 2000.0};
    TransactionTest() {}
};


TEST_F(TransactionTest, AmountTest) {
    EXPECT_EQ(transaction.getAmount(), 2000.0);
}


TEST_F(TransactionTest, SenderCardIdTest) {
    EXPECT_EQ(transaction.getSenderCardId(), "123");
}


TEST_F(TransactionTest, ReceiverCardIdTest) {
    EXPECT_EQ(transaction.getReceiverCardId(), "456");
}
TEST_F(TransactionTest, TransactionTimeTest) {
    std::string transactionTime = transaction.getTransactionTime();
    EXPECT_FALSE(transactionTime.empty());  // Проверяем, что время не пустое
}

TEST_F(TransactionTest, CommissionTest) {
    EXPECT_EQ(transaction.getCommission(), 0.0);
}

TEST_F(TransactionTest, MessageTest) {
    EXPECT_EQ(transaction.getMessage(), "No message");
}


