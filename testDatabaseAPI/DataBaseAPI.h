#pragma once
#include <iostream>
#include <curl/curl.h>

#include <string>
class DataBaseAPI
{
private:
	CURL* curl;
	CURLcode res;
	std::string URL;
public:
	DataBaseAPI();
	//void Intilize();
	void AddReader(int ReaderId,std::string Name , std::string IpAddress ,int AnteneaId ,int RSSI , std::string EPC ,int Direction);
	void SetUrl(std::string url);
	
};
