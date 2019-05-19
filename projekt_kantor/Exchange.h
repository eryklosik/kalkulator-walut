#pragma once
#include <string>
#include <map>
#include <iostream>
#include "Currency.h"
using namespace std;

class Exchange
{
private:
	map<string, Currency> currencies;

public:
	void printAllCurrencies();
	void addCurrency(double sellPrice, double buyPrice, string name);
	double calculateBuyPrice(string name, double amount);
	double calculateSellPrice(string name, double amount);
	Exchange();
	~Exchange();
};