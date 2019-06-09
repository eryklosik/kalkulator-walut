#include "pch.h"
#include <iostream>
#include "Country.h"
#include "Command.h"
using namespace std;

int main()
{
	string commandType;
	string currencyType = "";
	double ammount = 0;
	Command *command;
	Exchange exchange = Exchange();
	exchange.addCurrency(4.84, 4.88, "GBP"); //sprzedaz,kupno(od strony klienta)
	exchange.addCurrency(3.82, 3.85, "USD");
	exchange.addCurrency(4.27, 4.3, "EUR");
	exchange.addCurrency(2.62, 2.67, "AUD");
	exchange.addCurrency(2.8, 2.86, "CAD");
	exchange.addCurrency(3.79, 3.86, "CHF");
	exchange.addCurrency(0.16, 0.17, "CZK");
	exchange.addCurrency(0.56, 0.58, "DKK");
	exchange.addCurrency(0.43, 0.44, "NOK");
	exchange.addCurrency(0.4, 0.41, "SEK");
	exchange.addCurrency(5.2, 5.3, "XDR");
	
	while (true) {
		cin >> commandType;
		if (commandType=="buy" or commandType=="sell") {
			cin >> currencyType;
			if (!(cin >> ammount)) { //jesli uzytkownik poda 'nie-liczbe'
				commandType = "badarg"; //ustaw typ komendy na badarg, a klasa Command sie zajmie bledem
				cin.clear(); //wyczysc strumien wejsciowy
			}
		}
		command = new Command(commandType, currencyType, ammount);
		command->execute(exchange);
		delete command;
	}

	/*
	Exchange *kantor = new Exchange();
	kantor->addCurrency(4.84,4.88,"GBP"); //sprzedaz,kupno(od strony klienta)
	kantor->addCurrency(3.82,3.85,"USD");
	kantor->addCurrency(4.27,4.3,"EUR");
	kantor->printAllCurrencies();
	cout << "buy 100GBP: " << kantor -> calculateBuyPrice("GBP", 100) << "PLN"<< endl; //sprawdzenie dzialania
	cout << "sell 100GBP: " << kantor->calculateSellPrice("GBP", 100) << "PLN" << endl;
	return 0;*/
}