#include "pch.h"
#include "CurrencyDownloader.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

void CurrencyDownloader::downloadXML()
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &xmlText);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	
	this->doc.parse<0>(xmlText); //wywolaj metode obiektu xml_document ktora parsuje(czyta tekst i zamienia go w swoja strukture) tekst, w parse trzeba podac wskaznik na stringa zawierajacego tekst
}

void CurrencyDownloader::readCurriencies()
{
	std::cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
	std::string temp = "foobar";
	xml_node<> *node = doc.first_node("foobar");
	std::cout << "Node foobar has value " << node->value() << "\n";
	for (xml_attribute<> *attr = node->first_attribute();
		attr; attr = attr->next_attribute())
	{
		std::cout << "Node foobar has attribute " << attr->name() << " ";
		std::cout << "with value " << attr->value() << "\n";
	}
}

CurrencyDownloader::CurrencyDownloader()
{
}


CurrencyDownloader::~CurrencyDownloader()
{
}
