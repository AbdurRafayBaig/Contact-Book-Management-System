#include<iostream>
#include"ContactsBook.h"
#include<fstream>
using namespace std;
ContactsBook:: ContactsBook(){}
int ContactsBook::totalContacts()
{
	return contacts_count;
}
bool ContactsBook::contactBookFull()
{
	if (contacts_count >= size_of_contacts)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void ContactsBook::addContact()
{
	if (contactBookFull())
	{
		for (int i = 0; i < size_of_contacts; i++)
		{
			if (!contacts_list[i].check_contacts_list_zero())
			{
				contacts_list[i].getContact();
			}
		}
		resizeArray();// Call the resize function for Array
		for (int i = start_index; i < size_of_contacts; i++)
		{
			contacts_list[i].getContact();
			First_name[i] = contacts_list[i].add_first_name();
			Last_name[i] = contacts_list[i].add_last_name();
			contacts_count++;
		}
		
	}
}
void ContactsBook::resizeArray()
{
	int i = 0;
	cout << "\nEnter The Number of People : ";
	while ((!(std::cin >> input_resize) || input_resize <= 0))// For input Buffer 
	{
		std::cerr << "\n<<<<<<<<<<<<<< Enter Valid Number ,> 0  >>>>>>>>>>>>>>>>>\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	size_of_contacts_resize = size_of_contacts_resize + input_resize;
	First_name_resize = new string[size_of_contacts_resize];
	Last_name_resize = new string[size_of_contacts_resize];
	Temp_obj_ptr = new Contact[size_of_contacts_resize];
	ptr_resize = new Contact[size_of_contacts_resize];
	start_index = size_of_contacts;
	if (i < size_of_contacts)
	{
		for (i = 0; i < size_of_contacts; i++)
		{
			Last_name_resize[i] = Last_name[i];// Data copy from one file to another
			First_name_resize[i] = First_name[i];
			ptr_resize[i] = contacts_list[i];
		}
	}
	Last_name = Last_name_resize;
	First_name = First_name_resize;
	contacts_list = ptr_resize;
	size_of_contacts = size_of_contacts_resize;
}
// Search Contacts through Name 
Contact* ContactsBook::search_contact(std::string First_name, std::string Last_name)
{
	bool is_found=true;
	
	for (int i = 0; i < size_of_contacts; i++)
	{
	  is_found = contacts_list[i].search_through_name(First_name, Last_name);
	  if (is_found)
	  {
		  cout << "First Name\t\tLast Name\t\tMobile Number\t\t\tEmail Address\t\tCountry\t\tCity\t\tStreet\tHouse\n";
		  printSearchDetail(i);
		  return NULL;
	  }
	}
	cout << "Your Contact Can not Found \n";
	return NULL;
}
// Print details of contacts 
void ContactsBook::printDetail()
{
	cout << "First Name\t\tLast Name\t\tMobile Number\t\t\tEmail Address\t\tCountry\t\tCity\t\tStreet\tHouse\n";
	for (int i = 0; i < size_of_contacts; i++)
	{
		cout << i << " . ";
		contacts_list[i].printContact();
	}
}
// Search through Number 
Contact* ContactsBook::search_contact(std::string number)
{
	bool is_found;
	for (int i = 0; i < size_of_contacts; i++)
	{
		is_found = contacts_list[i].search_through_number(number);
		if (is_found)
		{
			cout << "First Name\t\tLast Name\t\tMobile Number\t\t\tEmail Address\t\tCountry\t\tCity\t\tStreet\tHouse\n";
			printSearchDetail(i);
			return NULL;
		}
	}
	cout << "Your Contact Can not Found \n";
	return NULL;
}
// Search through address
Contact* ContactsBook::search_contacts(string address_city, string address_street, string address_house)
{
	bool is_found;
	for (int i = 0; i < size_of_contacts; i++)
	{
		is_found = contacts_list[i].search_through_address(address_city, address_street, address_house);
		if (is_found)
		{
			cout << "First Name\t\tLast Name\t\tMobile Number\t\t\tEmail Address\t\tCountry\t\tCity\t\tStreet\tHouse\n";
			printSearchDetail(i);
			return NULL;
		}
	}
	cout << "Your Contact Can not Found \n";
	return NULL;
}
void ContactsBook::print_contacts_sorted(string choice)
{
	string swap;
	if (choice == "1")
	{
		for (int i = 0; i < size_of_contacts; i++)
		{
			for (int j = 1 ; j < size_of_contacts ; j++)
			{
				if (First_name[i].compare(First_name[j])>0)
				{
					swap = First_name[i];
					First_name[i] = First_name[j];
					First_name[j] = swap;
				}
			}
		}
		for (int i = 0; i < size_of_contacts; i++)
		{
			cout <<i<<". [ " << First_name[i] << " ] ";
		}
	}
	else
	{
		for (int i = 0; i < size_of_contacts; i++)
		{
			for (int j = 1; j < size_of_contacts ; j++)
			{
				if (First_name[i].compare(First_name[j]) > 0)
				{
					swap = Last_name[i];
					Last_name[i] = Last_name[j];
					Last_name[j] = swap;
				}
			}
		}
		for (int i = 0; i < size_of_contacts; i++)
		{
			cout <<" [ " << Last_name[i] << " ] ";
		}
	}
	
}
void ContactsBook::printSearchDetail(int index)
{
	contacts_list[index].printContact();
}
void ContactsBook::operator=( Contact& other)
{
	copycontacts(other);
}
void ContactsBook::rearrange_contact()
{
	for (int i = 0; i < size_of_contacts; i++)
	{
		Temp_obj_ptr[i] = contacts_list[i];
	}
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (Temp_obj_ptr[i].check_contacts_list_zero())
		{
			contacts_list[i] = Temp_obj_ptr[i];
		}
		else
		{
			contacts_list[i].getContact();
		}
	}
}
void ContactsBook::merge_duplicate()
{
	for (int i = 0; i < size_of_contacts; i++)
	{
		for (int j = i+1; j < size_of_contacts; j++)
		{
			if (contacts_list[i] == contacts_list[j] )
			{
				contacts_list[i].contacts_list_zero();
			}
		}
	}
	rearrange_contact();
}
void ContactsBook::save_to_file(std::string file_name)
{
	for (int i = 0; i < size_of_contacts; i++)
	{
		contacts_list[i].data_store_to_file(file_name);
	}
}
void ContactsBook::load_from_file(std::string file_name)
{
	cout << "First Name\t\tLast Name\t\tMobile Number\t\t\tEmail Address\t\tCountry\t\tCity\t\tStreet\tHouse\n";
	for (int i = 0; i < size_of_contacts; i++)
	{
		contacts_list[i].data_take_from_file(file_name);
	}
}
void ContactsBook::printDetailSingleContact(int i )
{
		printSearchDetail(i);
		cout << "1.Update The Contact Detail\n2.Delete The Contact ";
		cin >> update_delete_contact;
		cout << endl;
		if (update_delete_contact == 1)
		{
			contacts_list[i].getContact();
		}
		else if (update_delete_contact==2)
		{
			contacts_list[i].contacts_list_zero();

			cout << "\n\n!****************Contact Deleted Succefully **********************\n\n";
			
		}
}
void SearchHistory::addSearchHistoryName(string first_name,string last_name)
{
		First_name = first_name ;
		Last_name = last_name   ;
		ofstream output("SearchHistory.txt",ios::app);
		if (output.is_open())
		{
			output << first_name << " " << last_name << " ";
			output.close();
		}
		else
		{
			cerr << "\n\033[1;31m!.............. File Can not Open ...........! \n";
			cout << "\033[1;36m";
		}
}
void SearchHistory::addSearchHistoryPhone(string phone)
{
		Phone_number = phone;
		ofstream output("SearchHistory.txt", ios::app);
		if (output.is_open())
		{
			output << phone << " ";
			output.close();
		}
		else
		{
			cerr << "\n\033[1;31m!.............. File Can not Open ...........! \n";
			cout << "\033[1;36m";
		}
}
void SearchHistory::addSearchHistoryAddress(string city, string street, string house)
{
		City = city;
		Street = street;
		House = house;
		ofstream output("SearchHistory.txt", ios::app);
		if (output.is_open())
		{
			output << city << " " << street << " "<<house<<" ";
			output.close();
		}
		else
		{
			cerr << "\n\033[1;31m!.............. File Can not Open ...........! \n";
			cout << "\033[1;36m";
		}
}
void SearchHistory::displaySearchHistory()
{
	std::cout << "\n\n*************************************************\n";
	if (First_name!=" "||Last_name!=" ")
	{
		cout << "\nSearch Through Names :- \n";
		cout << "\n======================================\n";
		cout << "First Name :: " << First_name << endl;
		cout << "Last Name :: " << Last_name << endl;
		cout << "\n======================================\n";
	}
    if (Phone_number!=" ")
	{
		cout << "\nSearch Through Phones :- \n";
		cout << "\n======================================\n";
		cout << "Phone Number :: " << Phone_number << endl;
		cout << "\n======================================\n";
	}
    if (City!=" "||Street!=" "||House!=" ")
	{
		cout << "\nSearch Through Address :- \n";
		cout << "\n======================================\n";
		cout << "City :: " << City << endl;
		cout << "Street Number :: " << Street << endl;
		cout << "House Number :: " << House << endl;
		cout << "\n======================================\n";
	}
	std::cout << "\n\n*************************************************\n";
}
Contact ContactsBook::addContactGroup(int index)
{
	return contacts_list[index];
}
int ContactsBook:: sizeOfContacts()
{
	return size_of_contacts;
}
void ContactsBook::advanceSearch(string search_string)
{
	for (int i = 0; i < search_string.size(); i++)
	{
		for (int j = 0; j < size_of_contacts; j++)
		{
			contacts_list[j].advanceSearchContacts(search_string[i]);
		}
	}
	
}