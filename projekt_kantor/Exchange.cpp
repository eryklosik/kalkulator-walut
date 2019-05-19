#include "pch.h"
#include "Exchange.h"


void Exchange::printAllCurrencies()
{
	map<string, Currency>::iterator it;
	for (it = currencies.begin(); it != currencies.end(); it++)
		cout << it->first << " cena zakupu: " << it->second.getSellPrice() << " cena sprzedazy: " << it->second.getBuyPrice() << endl;
}

void Exchange::addCurrency(double sellPrice, double buyPrice, string name)
{
	map<string, Currency>::iterator search = currencies.find(name);
	if (search == currencies.end()) {
		Currency c(sellPrice, buyPrice, name);
		this->currencies[name] = c;
	}
	else {
		search->second.setSellPrice(sellPrice);
		search->second.setBuyPrice(buyPrice);
	}
}

double Exchange::calculateBuyPrice(string name, double amount)
{
	map<string, Currency>::iterator search = currencies.find(name);
	if (search == currencies.end()) {
		return 0.0;
	}
	else {
		return amount / currencies[name].getBuyPrice(); //zwracamy ile sie dostanie USD za tyle i tyle PLN
	}
}

double Exchange::calculateSellPrice(string name, double amount)
{
	map<string, Currency>::iterator search = currencies.find(name);
	if (search == currencies.end()) {
		return 0.0;
	}
	else {
		return amount * currencies[name].getSellPrice(); //zwracamy ile sie dostanie PLN za tyle i tyle USD
	}
}

Exchange::Exchange()
{
}

Exchange::~Exchange()
{
}