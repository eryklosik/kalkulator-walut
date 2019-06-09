#include "pch.h"
#include "Exchange.h"


void Exchange::printOneCurrency(string name)
{
	map<string, Currency>::iterator search = currencies.find(name); //ustaw iterator na 'szukana walute'
	if (search == currencies.end()) { //jesli iterator=end
		cout << "No such currency in database" << endl; //wypisz komunikat o braku
	}
	else {
		cout << search->second.toString() << endl; //komunikat wypisujacy 'toStringa' szukanej waluty
	}
}

void Exchange::printAllCurrencies()
{
	map<string, Currency>::iterator it;
	for (it = currencies.begin(); it != currencies.end(); it++) //przejdz po wszystkich elementach mapy i wyswietl ich toString
		cout << it->second.toString() << endl;
}

void Exchange::addCurrency(double sellPrice, double buyPrice, string name)
{
	map<string, Currency>::iterator search = currencies.find(name); //sprawdz czy taka waluta juz jest w bazie
	if (search == currencies.end()) { //jesli nie ma to dodaj nowa
		Currency c(sellPrice, buyPrice, name);
		this->currencies[name] = c;
	}
	else { //jesli jest to ustaw jej nowy kurs
		search->second.setSellPrice(sellPrice);
		search->second.setBuyPrice(buyPrice);
	}
}

double Exchange::calculateBuyPrice(string name, double amount)
{
	map<string, Currency>::iterator search = currencies.find(name); //sprawdz czy jest w bazie
	if (search == currencies.end()) { //jesli nie ma to zwroc '0'
		throw "No such currency in database"; //jesli nie ma waluty, rzuc wyjatek
	}
	else {
		return amount * currencies[name].getBuyPrice(); //zwracamy ile potrzeba PLN do zakupu tyle i tyle USD
	}
}

double Exchange::calculateSellPrice(string name, double amount)
{
	map<string, Currency>::iterator search = currencies.find(name);
	if (search == currencies.end()) {
		throw "No such currency in database";
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