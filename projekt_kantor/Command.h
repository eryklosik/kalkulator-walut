#pragma once
#include <string>
#include "Exchange.h"
using namespace std;

enum CommandType { //wszystkie mozliwe typy komend, w enumie zeby mozna bylo po nich switchowac
	EXIT,
	HELP,
	LIST,
	BUY,
	SELL,
	BADARG
};

class Command
{
private:
	CommandType commandType;
	string currencyType;
	double ammount;
	const string helpMessage = "Possible commands:\n"
							   "exit - exit the program\n"
							   "help - display this message\n"
							   "list - list all currency courses\n"
							   "buy 'currency type' 'ammount' - calculates buy price of selected ammount of currency type\n"
		                       "sell 'currency type' 'ammount' - calculates sell price of selected ammount of currency type\n";
public:
	CommandType getCommandType();
	string getCurrencyType();
	double getAmmount();
	void execute(Exchange exchange);
	CommandType parseCommand(string type);
	Command(string commandType, string currencyType, double ammount);
	Command(string commandType);
	Command();
	~Command();
};

