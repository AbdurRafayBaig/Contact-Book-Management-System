#pragma once
#ifndef ContactsBook_h
#define ContactsBook_h
#include "Address.h"
#include "Contact.h"
#include <iostream>
#include <string>
#include<chrono>
#include<ctime>
class ContactsBook:public Contact 
{
protected:
	// Make header file  and declare Attribute and methods
	Contact* contacts_list; // array of contacts
	Contact* ptr_resize;
	string* First_name;
	string* First_name_resize;
	string* Last_name;
	string* Last_name_resize;
	Contact* Temp_obj_ptr;
	int size_of_contacts=0;// storage limit
	int size_of_contacts_resize = 0;
	int contacts_count=0; // total contacts currently stored, next contact will be 
	// stored at this count plus 1 index
	int count_for_contacts = 0;
	int start_index;// For appending the data 
	int input_resize = 0;
	int update_delete_contact = 0;
public:
	// Declare Methods give signatur
	ContactsBook();
	int count_of_array_contacts;
	void addContact();
	//int total_contacts();
	int totalContacts();
	void printDetail();
	void printSearchDetail(int index);
	bool contactBookFull();
	void resizeArray();
	void operator = ( Contact& other);
	void merge_duplicate();
	void rearrange_contact();
	Contact* search_contact(std::string First_name, std::string Last_name);
	Contact* search_contact(std::string number);
	Contact* search_contacts(string address_city, string address_street, string address_house);
	void print_contacts_sorted(string choice); 
	void load_from_file(string file_name);
	void save_to_file(string file_name);
	void printDetailSingleContact(int  i);
	Contact addContactGroup(int index);
	int sizeOfContacts();
	//void addSearchString(string searchstring);
	void advanceSearch(string search_string);
	~ContactsBook()
	{
		delete contacts_list;
		delete ptr_resize;
		delete First_name;
		delete First_name_resize;
		delete Last_name;
		delete Last_name_resize;
		delete Temp_obj_ptr;
		contacts_list = NULL;
		ptr_resize = NULL;
		First_name = NULL;
		First_name_resize = NULL;
		Last_name = NULL;
		Last_name_resize = NULL;
		Temp_obj_ptr = NULL;
	}
};
class SearchHistory
{
protected :
	string First_name=" ", Last_name = " ", Phone_number = " ";
	string City = " ", Street = " ", House = " ";
	
public:
	void addSearchHistoryName(string first_name,string last_name);
	void addSearchHistoryPhone(string phone);
	void addSearchHistoryAddress(string city, string street, string house);
	void displaySearchHistory();
};
#endif 