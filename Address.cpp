#include<iostream>
#include <string>
#include "Address.h"
#include<sstream>
using namespace std;
Address:: Address(){}
Address:: Address(std::string house, std::string street, std::string city, std::string country)
{
	house = "White House";
	street = "5";			
	city = "Helsinki";
	country = "Pakistan";
}
void Address::getAddress()
{
	cout << "Enter Country Name : ";
	getline(cin, country);
	cout << "Enter City Name : ";
	getline(cin, city);
	cout << "Enter Street Number : ";
	getline(cin, street);
	cout << "Enter House Number : ";
	getline(cin, house);
}
void Address::print_address()
{
	cout <<"\t|" << country << "\t|" << city << "\t\t|" << street << "\t|" << house << "\n";
}
bool Address::equals(const Address& address)
{
	if (country == address.country && city == address.city && street == address.street && house == address.house)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Address::search_through_address(string address_city, string address_street, string address_house)
{
	if (city == address_city && street == address_street && house == address_house)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Address::copy_address(Address& other)
{
	house = other.house;
	city = other.city;
	street = other.city;
	country = other.country;
}
void Address::data_store_to_file(string file_name) {
	ofstream output(file_name, ios::app);
	if (output.is_open()) {
		output << house << " " << street << " " << city << " " << country << " ";
		output.close();
	}
	else {
		cout << "\nFile Not Found \n";
	}
}
void Address::data_take_from_file(string file_name)
{
	ifstream input(file_name,ios::in);
	string get_data;
	if (input.is_open())
	{
		while (getline(input, get_data))
		{
			stringstream sss(get_data);
			sss >> house >> street >> city >> country;
			cout << "\t|" << country << "\t|" << city << "\t\t|" << street << "\t|" << house << "\n";
		}
	}
	else
	{
		cout << "\n File Can not Open\n";
	}
	input.close();
}
void Address::advanceSearchAddress(char ch)
{
	bool isMatch = false;
	char lower_aplhabet;
	lower_aplhabet = ch;
	lower_aplhabet = tolower(lower_aplhabet);
	for (int i = 0; i < house.size(); i++)
	{
		if (ch == house[i] || lower_aplhabet == house[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << "House Number :: ";
		for (int i = 0; i < house.size(); i++)
		{
			if (ch == house[i] || lower_aplhabet == house[i])
			{
				cout << "\033[1;33m";
				cout << house[i];
			}
			else
			{
				cout << "\033[1;36m";
				cout << house[i];
			}
		}
		cout << endl;
	}
	isMatch = false;
	for (int i = 0; i < street.size(); i++)
	{
		if (ch == street[i] || lower_aplhabet == street[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << "Street Number :: ";
		for (int i = 0; i < street.size(); i++)
		{
			if (ch == street[i] || lower_aplhabet == street[i])
			{
				cout << "\033[1;33m";
				cout << street[i];
			}
			else
			{
				cout << "\033[1;36m";
				cout << street[i];
			}
		}
		cout << endl;
	}
	isMatch = false;
	for (int i = 0; i < city.size(); i++)
	{
		if (ch == city[i] || lower_aplhabet == city[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << " City Name :: ";
		for (int i = 0; i < city.size(); i++)
		{
			if (ch == city[i] || lower_aplhabet == city[i])
			{
				cout << "\033[1;33m";
				cout << city[i];
			}
			else
			{
				cout << "\033[1;36m";
				cout << city[i];
			}
		}
		cout << endl;
	}
	isMatch = false;
	for (int i = 0; i < country.size(); i++)
	{
		if (ch == country[i] || lower_aplhabet == country[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << "Country Name  :: ";
		for (int i = 0; i < country.size(); i++)
		{
			if (ch == country[i] || lower_aplhabet == country[i])
			{
				cout << "\033[1;33m";
				cout << country[i];
			}
			else
			{
				cout << "\033[1;36m";
				cout << country[i];
			}
		}
		cout << endl;
	}
	cout << "\033[1;36m";
}