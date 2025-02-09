#include "gtest/gtest.h"
#include "../include/currencyExchange.h"

class CurrencyExchangeTest : public ::testing::Test {
protected:
    CurrencyExchange exchange;

    CurrencyExchangeTest() {

    }
};


TEST_F(CurrencyExchangeTest, ConvertRubToEurTest) {
    double rub = 3582.0;
    double expectedEur = 1000.0;
    EXPECT_NEAR(exchange.convertRubToEur(rub), expectedEur, 0.001);
}


TEST_F(CurrencyExchangeTest, ConvertRubToUsdTest) {
    double rub = 3394.0;
    double expectedUsd = 1000.0;
    EXPECT_NEAR(exchange.convertRubToUsd(rub), expectedUsd, 0.001);
}

TEST_F(CurrencyExchangeTest, ConvertEurToRubTest) {
    double eur = 1000.0;
    double expectedRub = 3579.0;
    EXPECT_NEAR(exchange.convertEurToRub(eur), expectedRub, 0.001);
}

TEST_F(CurrencyExchangeTest, ConvertUsdToRubTest) {
    double usd = 1000.0;
    double expectedRub = 3390.0;
    EXPECT_NEAR(exchange.convertUsdToRub(usd), expectedRub, 0.001);
}

TEST_F(CurrencyExchangeTest, DisplayExchangeRatesTest) {
    testing::internal::CaptureStdout();
    exchange.displayExchangeRates();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Buy 1 USD = 3.394 RUB"), std::string::npos);
    EXPECT_NE(output.find("Sell 1 USD = 3.39 RUB"), std::string::npos);
    EXPECT_NE(output.find("Buy 1 EUR = 3.582 RUB"), std::string::npos);
    EXPECT_NE(output.find("Sell 1 EUR = 3.579 RUB"), std::string::npos);
}

