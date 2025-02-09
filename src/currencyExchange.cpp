#include "../include/currencyExchange.h"

CurrencyExchange::CurrencyExchange()
    : rubToEurBuy(3.582), rubToUsdBuy(3.394), eurToRubSell(3.579), usdToRubSell(3.39) {}

double CurrencyExchange::convertRubToEur(double rub) const {
    return rub / rubToEurBuy;
}

double CurrencyExchange::convertRubToUsd(double rub) const {
    return rub / rubToUsdBuy;
}

double CurrencyExchange::convertEurToRub(double eur) const {
    return eur * eurToRubSell;
}

double CurrencyExchange::convertUsdToRub(double usd) const {
    return usd * usdToRubSell;
}

void CurrencyExchange::displayExchangeRates() const {
    std::cout << "Currency Exchange Rates:\n";
    std::cout << "Buy 1 USD = " << rubToUsdBuy << " RUB\n";
    std::cout << "Sell 1 USD = " << usdToRubSell << " RUB\n";
    std::cout << "Buy 1 EUR = " << rubToEurBuy << " RUB\n";
    std::cout << "Sell 1 EUR = " << eurToRubSell << " RUB\n";
}
