#pragma once
#include <string>
#include <iostream>
#include <rapidxml.hpp>
#include <fstream> //do przeczytania z pliku tego co pobieram
#include <curl/curl.h> //pobiera zawartosc strony internetowej
#include <curl/easy.h>
using namespace rapidxml; //zeby nie pisac przed kazda funkcja biblioteczna rapidxml ::

class CurrencyDownloader
{

private:
	const std :: string URL = "https://www.nbp.pl/kursy/xml/c110z190607.xml";
	xml_document<> doc;
	char* xmlText;
public:
	void downloadXML();
	void readCurriencies();
	CurrencyDownloader();
	~CurrencyDownloader();
};