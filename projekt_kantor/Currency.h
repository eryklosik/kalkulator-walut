#pragma once
#include <string>
using namespace std;

class Currency
{
private:
	string name;
	double sellPrice;
	double buyPrice;

public:
	double getSellPrice();
	double getBuyPrice();
	string getName();
	void setSellPrice(double newPrice);
	void setBuyPrice(double newPrice);
	string toString(); //wyswietla wszystkie informacje o walucie
	Currency();
	Currency(double sellPrice, double buyPrice, string name);
	~Currency();
};