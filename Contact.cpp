#include<iostream>
#include<string>
#include"Contact.h"
#include<sstream>
using namespace std;
Contact:: Contact() {}
 Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address)
{
	first_name = "aaa";
	last_name = "lll";
	mobile_number = "sss";
	email_address = "eee";
}
void Contact::getContact()
{
	cin.ignore();
	cout << "Enter First Name : ";
	getline(cin, first_name);
	add_first_name();
	cout << "Enter Last Name : ";
	getline(cin, last_name);
	cout << "Enter Mobile Number : ";
	getline(cin, mobile_number);
	cout << "Enter Email Address : ";
	getline(cin, email_address);
	Address::getAddress();
}
string Contact::add_first_name()
{
	return first_name;
}
string Contact::add_last_name()
{
	return last_name;
}
void Contact::printContact()
{
	cout << first_name <<"\t\t|" << last_name <<"\t\t\t|" << mobile_number <<"\t\t\t|" << email_address<<"\t|";
	Address::print_address();
}
bool Contact::equals(const Contact& contact)
{
	if (first_name == contact.first_name && last_name == contact.last_name && mobile_number == contact.mobile_number && email_address == contact.email_address)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Contact::search_through_name(string First_name, string Last_name)
{
	if (First_name == first_name && Last_name == last_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Contact::search_through_number(string number)
{
	if (number == mobile_number)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Contact::copycontacts(Contact&other)
{
	copy_address(other);
	first_name = other.first_name;
	last_name = other.last_name;
	mobile_number = other.mobile_number;
	email_address = other.email_address;
}
bool Contact::operator ==(const Contact& other)
{
	if (first_name == other.first_name&&last_name==other.last_name&&mobile_number==other.mobile_number&&email_address==other.email_address)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Contact::contacts_list_zero()
{
	first_name = "0";
	last_name = "0";
	mobile_number = "0";
	email_address = "0";
}
bool Contact::check_contacts_list_zero()
{
	if (first_name == "0" && last_name == "0" && mobile_number == "0" && email_address == "0")
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Contact::data_store_to_file(string file_name)
{
	ofstream output(file_name, ios::app);
	if (output.is_open())
	{
		output << first_name << " " << last_name << " " << mobile_number << " " << email_address << " ";
		output.close();
	}
	else
	{
		cout << "\nFile Not Found \n";
	}
	Address::data_store_to_file(file_name);
}

void Contact::data_take_from_file(string file_name)
{
	ifstream input(file_name);
	string get_data;
	if (input.is_open())
	{
		while (getline(input, get_data))
		{
			stringstream ss(get_data);
			cout << first_name << "\t\t|" << last_name << "\t\t\t|" << mobile_number << "\t\t\t|" << email_address << "\t|";
			ss >> first_name >> last_name >> mobile_number >> email_address;
		}
		input.close();
	}
	else
	{
		cout << "File Not Found" << endl;
	}
	Address::data_take_from_file(file_name);
}
void Contact::advanceSearchContacts(char ch)
{
	
	bool isMatch = false;
	char lower_aplhabet;
	lower_aplhabet = ch;
	lower_aplhabet = tolower(lower_aplhabet);
	for (int i = 0; i < first_name.size(); i++)
	{
		if (ch == first_name[i] || lower_aplhabet == first_name[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << "First Name  :: ";
		for (int i = 0; i < first_name.size(); i++)
		{
			if (ch == first_name[i]|| lower_aplhabet==first_name[i])
			{
				cout << "\033[1;33m";
				cout << first_name[i];
			}
			else
			{
				cout << "\033[1;36m";
				cout << first_name[i];
			}
		}
		cout << endl;
	}
	isMatch = false;
	for (int i = 0; i < last_name.size(); i++)
	{
		if (ch == last_name[i] || lower_aplhabet == last_name[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << "Last Name  :: ";
		for (int i = 0; i < last_name.size(); i++)
		{
			if (ch == last_name[i] || lower_aplhabet == last_name[i])
			{
				cout << "\033[1;33m";
				cout << last_name [i] ;
			}
			else
			{
				cout << "\033[1;36m";
				cout << last_name[i];
			}
		}
		cout << endl;
	}
	isMatch = false;
	for (int i = 0; i < mobile_number.size(); i++)
	{
		if (ch == mobile_number[i] || lower_aplhabet == mobile_number[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << "Mobile Number  :: ";
		for (int i = 0; i < mobile_number.size(); i++)
		{
			if (ch == mobile_number[i] || lower_aplhabet == mobile_number[i])
			{
				cout << "\033[1;33m";
				cout << mobile_number[i];
			}
			else
			{
				cout << "\033[1;36m";
				cout << mobile_number[i];
			}
		}
		cout << endl;
	}
	isMatch = false;
	for (int i = 0; i < email_address.size(); i++)
	{
		if (ch == email_address[i] || lower_aplhabet == email_address[i])
		{
			isMatch = true;
		}
	}
	if (isMatch == true)
	{
		cout << "Email Address  :: ";
		for (int i = 0; i < email_address.size(); i++)
		{
			if (ch == email_address[i] || lower_aplhabet == email_address[i])
			{
				cout << "\033[1;33m";
				cout << email_address[i];
			}
			else
			{
				cout << "\033[1;36m";
				cout << email_address[i];
			}
		}
		cout << endl;
	}
	cout << "\033[1;36m";
	advanceSearchAddress(ch);
}