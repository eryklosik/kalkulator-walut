#include "pch.h"
#include <iostream>
#include "Country.h"
#include "Exchange.h"
using namespace std;

int main()
{
	Exchange *kantor = new Exchange();
	kantor->addCurrency(4.84,4.88,"GBP"); //sprzedaz,kupno(od strony klienta)
	kantor->addCurrency(3.82,3.85,"USD");
	kantor->addCurrency(4.27,4.3,"EUR");
	kantor->printAllCurrencies();
	cout << "buy 100GBP: " << kantor -> calculateBuyPrice("GBP", 100) << "PLN"<< endl; //sprawdzenie dzialania
	cout << "sell 100GBP: " << kantor->calculateSellPrice("GBP", 100) << "PLN" << endl;
	return 0;
}