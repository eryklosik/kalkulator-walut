#include "pch.h"
#include "Currency.h"


double Currency::getSellPrice()
{
	return this->sellPrice;
}

double Currency::getBuyPrice()
{
	return this->buyPrice;
}

string Currency::getName()
{
	return this->name;
}

void Currency::setSellPrice(double newPrice)
{
	this->sellPrice = newPrice;
}

void Currency::setBuyPrice(double newPrice)
{
	this->buyPrice = newPrice;
}

string Currency::toString()
{
	return this->name + " sell price: " + to_string(this->sellPrice) + " buy price: " + to_string(this->buyPrice); //to_string zmienia double na stringa, cala metoda zwraca stringowa reprezentacje obiektu
}

Currency::Currency()
{
}


Currency::Currency(double sellPrice, double buyPrice, string name)
{
	this->sellPrice = sellPrice;
	this->buyPrice = buyPrice;
	this->name = name;
}

Currency::~Currency()
{
}
