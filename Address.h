#pragma once
#ifndef Address_h
#define Address_h
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
// Make header file  and declare Attribute and methods
class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	// Declare Methods give signatur
	void getAddress();
	bool equals(const Address& address);
	void print_address();
	void copy_address(Address& other);
	bool search_through_address(string address_city, string address_street, string address_house);
	void data_store_to_file(string file_name);
	void data_take_from_file(string file_name);
	void advanceSearchAddress(char ch);
	Address(std::string house, std::string street, std::string city, std::string country);
	Address();
};
#endif
