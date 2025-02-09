#pragma once


#include <iostream>

class CurrencyExchange {
private:
    double rubToEurBuy;
    double rubToUsdBuy;
    double eurToRubSell;
    double usdToRubSell;

public:
    CurrencyExchange();

    double convertRubToEur(double rub) const;
    double convertRubToUsd(double rub) const;
    double convertEurToRub(double eur) const;
    double convertUsdToRub(double usd) const;

    void displayExchangeRates() const;
};
