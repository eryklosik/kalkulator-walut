#include "pch.h"
#include "Command.h"
#include <iostream>


CommandType Command::getCommandType()
{
	return this->commandType;
}

string Command::getCurrencyType()
{
	return this->currencyType;
}

double Command::getAmmount()
{
	return this->ammount;
}

void Command::execute(Exchange exchange)
{
	switch (commandType) {
	case EXIT:
		cout << "Program has ended" << endl;
		exit(0);
		break;
	case HELP:
		cout << helpMessage;
		break;
	case LIST:
		exchange.printAllCurrencies();
		break;
	case BUY:
		try{
		cout << "Buy price: " << exchange.calculateBuyPrice(this->currencyType, this->ammount) << endl;
		}
		catch (const char* e) {
			cout << e << endl;
		}
		break;
	case SELL:
		try {
			cout << "Sell price: " << exchange.calculateSellPrice(this->currencyType, this->ammount) << endl;
		}
		catch (const char* e) {
			cout << e << endl;
		}
		break;
	case BADARG:
		cout << "Second argument of buy and sell has to be a number. " << endl;
		break;
	}
}

CommandType Command::parseCommand(string type)
{
	if (type == "exit")
		return EXIT;
	if (type == "list")
		return LIST;
	if (type == "buy")
		return BUY;
	if (type == "sell")
		return SELL;
	if (type == "badarg")
		return BADARG;
	return HELP;
}

Command::Command(string commandType, string currencyType, double ammount)
{
	this->commandType = parseCommand(commandType);
	this->currencyType = currencyType;
	this->ammount = ammount;
}

Command::Command(string commandType)
{
	this->commandType = parseCommand(commandType);
}

Command::Command()
{
}


Command::~Command()
{
}
