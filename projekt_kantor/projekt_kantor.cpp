#include "pch.h"
#include <iostream>
#include "Country.h"
#include "Exchange.h"
using namespace std;

int main()
{
	Exchange *kantor = new Exchange();
	kantor->addCurrency(4.5,2.25,"USD");
	kantor->addCurrency(1,2,"Cebula");
	kantor->addCurrency(2.5,7.2,"Gowno");
	kantor->printAllCurrencies();
	return 0;
}