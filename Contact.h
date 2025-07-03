#pragma once
#ifndef Contact_h
#define Contact_h
#include <iostream>
#include<string>
#include "Address.h"
class Contact :public Address
{
protected:
	// Make header file  and declare Attribute and methods
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	string get_data;

public:
	// Declare Methods give signatur
	void getContact();
	void printContact();
	bool equals(const Contact&contact);
	string add_first_name();
	string add_last_name();
	bool search_through_name(string First_name, string Last_name);
	bool search_through_number(string number);
	void copycontacts(Contact&other);
	bool operator ==(const Contact& other);
	void contacts_list_zero();
	bool check_contacts_list_zero();
	void data_store_to_file(string file_name);
	void data_take_from_file(string file_name);
	void advanceSearchContacts(char ch);
	bool operator==(const Contact& other) const {
		// Define equality criteria for Contacts
		// For example, if two contacts are equal if their names are the same
		return (first_name == other.first_name && last_name == other.last_name);
	}

	bool operator<(const Contact& other) const {
		// Define the less than operator for sorting
		// For example, compare based on first name
		return (first_name < other.first_name);
	}
	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address/*, Address* address*/);
};
#endif 