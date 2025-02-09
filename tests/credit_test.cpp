#include "gtest/gtest.h"
#include "../include/client.h"
#include "../include/credit.h"

class CreditTest : public ::testing::Test {
protected:
    Client client{"John Doe", 30, 10000.0, 5000.0, 2000.0};
    Credit credit{"credit1", 50000.0, 5.0, 12, &client};

    CreditTest() {

    }
};


TEST_F(CreditTest, CreateCreditTest) {
    EXPECT_EQ(credit.getId(), "credit1");
    EXPECT_EQ(credit.getPrincipalAmount(), 50000.0);
    EXPECT_EQ(credit.getInterestRate(), 5.0);
    EXPECT_EQ(credit.getTermMonths(), 12);
    EXPECT_GT(credit.getMonthlyPayment(), 0);
    EXPECT_TRUE(credit.getIsActive());
}

TEST_F(CreditTest, PartialPaymentTest) {
    double initialPrincipal = credit.getPrincipalAmount();
    double initialPayment = credit.getMonthlyPayment();

    credit.makePayment(initialPayment);

    EXPECT_LT(credit.getPrincipalAmount(), initialPrincipal);
    EXPECT_GT(credit.getPrincipalAmount(), 0.0);
    EXPECT_TRUE(credit.getIsActive());
}

TEST_F(CreditTest, FullPaymentTest) {
    double initialPrincipal = credit.getPrincipalAmount();
    credit.makePayment(initialPrincipal);

    EXPECT_EQ(credit.getPrincipalAmount(), 0.0);
    EXPECT_FALSE(credit.getIsActive());
}


TEST_F(CreditTest, MakePaymentAfterPaidOffTest) {
    credit.makePayment(credit.getPrincipalAmount());
    credit.makePayment(1000.0);

    EXPECT_EQ(credit.getPrincipalAmount(), 0.0);
    EXPECT_FALSE(credit.getIsActive());
}

TEST_F(CreditTest, DisplayCreditDetailsTest) {
    testing::internal::CaptureStdout();
    credit.displayCreditDetails();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Credit Details:"), std::string::npos);
    EXPECT_NE(output.find("Principal Amount: 50000"), std::string::npos);
    EXPECT_NE(output.find("Interest Rate: 5"), std::string::npos);
    EXPECT_NE(output.find("Term: 12 months"), std::string::npos);
    EXPECT_NE(output.find("Monthly Payment:"), std::string::npos);
    EXPECT_NE(output.find("Client: John Doe"), std::string::npos);
}

