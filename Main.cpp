// Include all the Header File 
#include<iostream>
#include<string>
#include<vector>
#include"Address.h"
#include"Contact.h"
#include"ContactsBook.h"
#include<algorithm>
#include<sstream>
using namespace std;
void Print_menue();
void removeDuplicate(std::vector<Contact>& group, int&duplicateCount);
int main()
{
	system("color 0b");
	// Declare all the varaible 
	string first_name, last_name, phone_number,city,house,street,choice_sorted_name,file_name;
	int Group_choice = 1, group_count = 0, choose_group_created = 0, group_count_family = 0,group_count_friend=0, contact_book_number=0;
	int size = 0, choice_single_contact_detail = 0, Duplicate_count_friend = 0, Duplicate_count_family = 0;
	int group_Delete_choice = 0,choose_group_delete=0;
	char choice_print_detail_or_not = 'Y';
	bool is_group_fill = false;
	string advance_search;
	Contact *ptr;
	ContactsBook* Obj_ptr;
	vector <SearchHistory>History_obj;
	vector<string>timeStrings;
	SearchHistory temp_obj;
	vector<Contact>G_Friend_obj;
	vector<Contact>G_Family_obj;
	cout << "=================================================================\n";
	cout << "Welcome To the Contact Books \n";
	cout << "=================================================================\n";
	cout << "Enter Number of Conacts Book : ";
	//std::cout << "\033[1;31mThis line will be red." << std::endl;
	while( (!(std::cin >> size) || size <= 0))
	{
		std::cerr << "\n\033[1;31m<<<<<<<<<<<<<< Enter Valid Number ,> 0  >>>>>>>>>>>>>>>>>\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "\033[1;36m";
	Obj_ptr = new ContactsBook[size];
	int choice=0, search_choice=0;
	Print_menue();
	// Call Function to print menu
	std::cin >> choice;
	// Take choice
	do
	{
		
		if (choice == 1)
		{
			for (int i = 0; i < size; i++)
			{
				Obj_ptr[i].addContact();// Add Number of Contacts
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < size; i++)
			{
				Obj_ptr[i].addContact();// Add Number of Contacts
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < size; i++)
			{
				Obj_ptr[i].merge_duplicate();// Merge Duplicate Contacts
			}
		}
		else if (choice == 4)
		{
			std::cin.ignore();
			for (int i = 0; i < size; i++)
			{
				// Stor data to file 
				cout << "Enter File Name : ";
				std::getline(std::cin, file_name);// Take File Name 
				cout << "File Name : " << file_name << endl;
				Obj_ptr[i].save_to_file(file_name);
			}
		}
		else if (choice == 5)
		{
			std::cin.ignore();
			for (int i = 0; i < size; i++)
			{
				// Data take form file 
				cout << "Enter File Name : ";
				std::getline(std::cin, file_name);// Take Data from file
				cout << "File Name : " << file_name << endl;
				Obj_ptr[i].load_from_file(file_name);
			}
		}
		else if (choice == 6)
		{
			cout << "1.First Name \n2.Last Name \n";
			std::cin.ignore();
			std::getline(std::cin, choice_sorted_name);
			for (int i = 0; i < size; i++)
			{
				// Print Contacts Sorted 
				cout << "\033[0;32m";
				cout << "\n!.......................List of Name..................!\n";
				cout << "\033[1;36m";
				cout << "-------------------------------------------------------------\n";
				Obj_ptr[i].print_contacts_sorted(choice_sorted_name);
				cout << "\n-------------------------------------------------------------\n";
			}
		}
		else if (choice == 7)
		{
			for (int i = 0; i < size; i++)
			{
				// Print all the details of Contacts
				cout << "\033[0;32m"; 
				cout << "\n!...........................Contact Book :: " << i << "........................!\n";
				cout << "\033[1;36m";
				Obj_ptr[i].printDetail();
			}
		}
		else if (choice == 8)
		{
			// Search throught contacts
			cout << "\033[0;32m"; 
			cout << "\n!......................Search Bar........................!\n";
			cout << "\033[1;36m";
			cout << "1.Search through Name\n2.Search Through Phone Number\n3.Search Through Address\n";
			while (!(std::cin >> search_choice) || search_choice <= 0 || search_choice > 3)
			{
				std::cerr << "\n\033[1;31m<<<<<<<<<<<<< Invalid Input >>>>>>>>>>>>>>\n1.Search through Name\n2.Search Through Phone Number\n3.Search Through Address";
			}
			cout << "\033[1;36m";
			if (search_choice == 1)
			{
				std::cin.ignore();
				cout << "Enter First Name : ";
				getline(std::cin, first_name);
				cout << "Enter Last Name : ";
				getline(std::cin, last_name);
				for (int i = 0; i < size; i++)
				{
					ptr = Obj_ptr[i].search_contact(first_name, last_name);
				}
				temp_obj.addSearchHistoryName(first_name, last_name);
				History_obj.push_back(temp_obj);
				auto currentTime = std::chrono::system_clock::now();
				std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
				char timeString[26];
				ctime_s(timeString, sizeof(timeString), &currentTimeT);
				timeStrings.push_back(timeString);
			}
			else if (search_choice == 2)
			{
				cout << "Enter Phone Number : ";
				std::cin.ignore();
				getline(std::cin, phone_number);
				for (int i = 0; i < size; i++)
				{
					ptr = Obj_ptr[i].search_contact(phone_number);
				}
				temp_obj.addSearchHistoryPhone(phone_number);
				History_obj.push_back(temp_obj);
				auto currentTime = std::chrono::system_clock::now();
				std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
				char timeString[26];
				ctime_s(timeString, sizeof(timeString), &currentTimeT);
				timeStrings.push_back(timeString);
			}
			else if (search_choice == 3)
			{
				cout << "Enter City : ";
				std::cin.ignore();
				getline(std::cin, city);
				cout << "Enter Street : ";
				getline(std::cin, street);
				cout << "Enter House : ";
				getline(std::cin, house);
				for (int i = 0; i < size; i++)
				{
					ptr = Obj_ptr[i].search_contacts(city, street, house);
				}
				temp_obj.addSearchHistoryAddress(city,street,house);
				History_obj.push_back(temp_obj);
				auto currentTime = std::chrono::system_clock::now();
				std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
				char timeString[26];
				ctime_s(timeString, sizeof(timeString), &currentTimeT);
				timeStrings.push_back(timeString);

			}	
		} 
		else if (choice == 9)
		{
			cout << "!.....................Number of Contacts......................! " << endl;
			for (int i = 0; i < size; i++)
			{
				// Count of Contacts Book 
				cout << "Number of Contacts in ContactsBook : " << i << " :: ";
				cout << Obj_ptr[i].totalContacts();
				cout << endl;
			}
		}
		else if (choice == 10)
		{
			for (int i = 0; i < size; i++)
			{
				cout << "\033[0;32m"; 
				cout << "\n!.......................List of Name..................!\n";
				cout << "\033[1;36m";
				cout << "-------------------------------------------------------------\n";
				Obj_ptr[i].print_contacts_sorted("1");
				cout << "\n-------------------------------------------------------------\n";
				cout << "Do You Want to Print Detail Of Any Contact From in This Contact Book ( Y / N ) :: ";
				while (!(std::cin >> choice_print_detail_or_not) || choice_print_detail_or_not != 'Y' && choice_print_detail_or_not != 'y' && choice_print_detail_or_not != 'N' && choice_print_detail_or_not != 'n')
				{
					cin.clear();
					std::cerr << "Enter Valid Choice ( Y / N ) ";
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				if (choice_print_detail_or_not == 'Y' || choice_print_detail_or_not == 'y' || choice_print_detail_or_not == 'N' || choice_print_detail_or_not == 'n')
				{
					cout << "Choose the Contact you want to  Print Detail :: ";
					cin >> choice_single_contact_detail;
					cout << endl;
					Obj_ptr[i].printDetailSingleContact(choice_single_contact_detail);
				}
			}
		}
		else if (choice == 11)
		{
			cout << "!..................... Search History .........................!\n";
			for (int i = 0; i < History_obj.size(); i++)
			{
				cout << "\033[0;32m"; 
				cout << "\nTime : - ";
				cout << timeStrings[i];
				cout << "\033[1;36m";
				History_obj[i].displaySearchHistory();
				
			}
		}
		else if (choice == 12)
		{
			cout << "\n******************* Create Group Section ********************\n";
			cout << "1.Family Group\n2.Friend Group\n";
			cin >> choose_group_created;
			if (choose_group_created == 1)
			{
				for (int i = 0; Group_choice != 6 || i != 5; i++)
				{
					for (int i = 0; i < size; i++)
					{
						// Print Contacts Sorted 
						cout << "******************* Contact Book :: " << i <<" ***************\n" << endl;
						cout << "\n!.......................List of Name..................!\n";
						cout << "-------------------------------------------------------------\n";
						Obj_ptr[i].print_contacts_sorted("1");
						cout << "\n-------------------------------------------------------------\n";
					}
					cout << "6.Exit\n";
					cout << "\nEnter The Contact Book Number :: ";
					while (!(std::cin >> contact_book_number) || contact_book_number > size)
					{
						cerr << "\n\033[1;31mChoose the Correct Contact Book \n";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					cout << "\033[1;36m";
					if (contact_book_number == 6)
					{
						break;
					}
					cout << "Choose the Contact You wan to Added :: ";
					while (!(std::cin >> Group_choice))
					{
						cerr << "\n\033[1;31mChoose the Correct Contact Book \n";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					cout << "\033[1;36m";
					if (Group_choice == 6)
					{
						break;
					}
					if (group_count_family == 5)
					{
						cout << "\n===========================================================\n";
						cout << "\n| !................... Group is Fill ..................! |\n";
						cout << "\n| Contact Can not Added in the Group                     |\n\n";
						cout << "\n===========================================================\n";
						break;
					}
					else
					{
						G_Family_obj.push_back(Obj_ptr[contact_book_number].addContactGroup(Group_choice));
						group_count_family++;
					}
				}	
			}
			else if (choose_group_created == 2)
			{
				for (int i = 0; Group_choice != 6 || i != 5; i++)
				{
					for (int i = 0; i < size; i++)
					{
						// Print Contacts Sorted 
						cout << "\n!.......................List of Name..................!\n";
						cout << "-------------------------------------------------------------\n";
						Obj_ptr[i].print_contacts_sorted("1");
						cout << "\n-------------------------------------------------------------\n";
					}
					cout << "6.Exit\n";
					cout << "\nEnter The Contact Book Number :: ";
					while (!(std::cin >> contact_book_number) || contact_book_number > size)
					{
						cerr << "\nChoose the Correct Contact Book \n";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					if (contact_book_number == 6)
					{
						break;
					}
					cout << "Choose the Contact You wan to Added :: ";
					while (!(std::cin >> Group_choice))
					{
						cerr << "\nChoose the Correct Contact \n";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					if (Group_choice == 6)
					{
						break;
					}
					if (group_count_friend == 5)
					{
						cout << "\033[1;31m";
						cout << "\n===========================================================\n";
						cout << "\n| !................... Group is Fill ..................! |\n";
						cout << "\n| Contact Can not Added in the Group                     |\n\n";
						cout << "\n===========================================================\n";
						break;
					}
					else
					{
						G_Friend_obj.push_back(Obj_ptr[contact_book_number].addContactGroup(Group_choice));
						group_count_friend++;
					}
					cout << "\033[1;36m";
				}
			}
		}
		else if (choice == 13)
		{
			
			for (int i = 0; i < size; i++)
			{
				removeDuplicate(G_Family_obj,Duplicate_count_family);
				removeDuplicate(G_Friend_obj, Duplicate_count_friend);
				group_count_family = group_count_family - Duplicate_count_family;
				group_count_friend = group_count_friend - Duplicate_count_friend;
				cout << "\n****************************\n";
				cout << "\nFamily Group  Detail "<< i << " : -\n";
				cout << "****************************\n";
				for (int i = 0; i < G_Family_obj.size(); i++)
				{
					cout << i << " . ";
					G_Family_obj[i].printContact();
				}
				cout << "\n****************************\n";
				cout << "\n\nFriend Group  Detail "<<i<<" : - \n";
				cout << "****************************\n";
				for (int i = 0; i < G_Friend_obj.size(); i++)
				{
					cout << i << " . ";
					G_Friend_obj[i].printContact();
				}
			}
			cout << "\nYou Want to Delete the Contact from Group \n1.Yes\n2.No\n";
			cin >> group_Delete_choice;
			if (group_Delete_choice == 1)
			{
				cout << "\nChoose the Group You Wan to Delete\n1.Family Group\n2.Friend Group\n";
				cin >> choose_group_delete;
				if (choose_group_delete == 1)
				{
					cout << "\nChoose the Contact Book :: ";
					while (!(std::cin >> contact_book_number) || contact_book_number > size)
					{
						cerr << "\nChoose the Correct Contact Book ::  ";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					if (contact_book_number == 6)
					{
						break;
					}
					cout << "Choose the Contact You wan to Delete :: ";
					while (!(std::cin >> Group_choice))
					{
						cerr << "\nChoose the Correct Contact :: ";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					if (Group_choice == 6)
					{
						break;
					}
					auto it = std::find(G_Family_obj.begin(), G_Family_obj.end(), Obj_ptr[contact_book_number].addContactGroup(Group_choice));
					if (it != G_Family_obj.end()) {
						G_Family_obj.erase(it);
						group_count_family--;
						cout << "\nContact From Group Delete Successfully\n";
					}
					
				}
				else if (choose_group_delete==2)
				{
					cout << "\nChoose the Contact Book ::  ";
					while (!(std::cin >> contact_book_number) || contact_book_number > size)
					{
						cerr << "\nChoose the Correct Contact Book :: ";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					if (contact_book_number == 6)
					{
						break;
					}
					cout << "Choose the Contact You wan to Delete :: ";
					while (!(std::cin >> Group_choice))
					{
						cerr << "\nChoose the Correct Contact \n";
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					if (Group_choice == 6)
					{
						break;
					}
					auto it = std::find(G_Friend_obj.begin(), G_Friend_obj.end(), Obj_ptr[contact_book_number].addContactGroup(Group_choice));
					if (it != G_Friend_obj.end()) {
						G_Friend_obj.erase(it);
						group_count_friend--;
						cout << "\nContact From Group Delete Successfully\n\n";
					}
				}
				
			}
			else  
			{
				cout << "\n !........... Exit From Group Section .............\n\n";
			}
		}
        else if (choice == 14)
        {
			cout << "\n\n!.............. Welcome to Advance Search .............!\n\n";
			cin.ignore();
			cout << "Enter which you want to search :: ";
			getline(cin, advance_search);
			for (int i = 0; i < size; i++)
			{
				Obj_ptr[i].advanceSearch(advance_search);
			}
		}
		else if (choice == 15)
		{
			cout << "\n<<<<<<<<<<<<< Thanks For Choosing Our Services >>>>>>>>>>>>>>>>>>>>>>\n";
			return 0;
		}
		std::cin.ignore();
		Print_menue();
		std::cin >> choice;
	} while (choice!=20);
	delete [] Obj_ptr;
	system("pause");
	return 0;
}
void Print_menue()// Print menu
{
	cout << "\n ====================================\n";
	cout << " | 1 . Create Contact List           |" << endl;
	cout << " | 2 . Add New Contact               |" << endl;
	cout << " | 3 . Merge Duplicate               |" << endl;
	cout << " | 4 . Store To File                 |" << endl;
	cout << " | 5 . Load From File                |" << endl;
	cout << " | 6 . Print Contacts Sorted         |" << endl;
	cout << " | 7 . Print Contacts                |" << endl;
	cout << " | 8 . Search Contacts               |" << endl;
	cout << " | 9 . Display All Count of Contacts |" << endl;
	cout << " | 10. Managing Contact              |" << endl;
	cout << " | 11. Searched History              |" << endl;
	cout << " | 12. Create Group                  |" << endl;
	cout << " | 13. Display Group                 |" << endl;
	cout << " | 14. Advance Search                |" << endl;
	cout << " | 15. Exit                          |" << endl;
	cout << " =====================================";
	cout << "\n\nEnter Your Choice :: " ;
}
void removeDuplicate(std::vector<Contact>& group, int&duplicateCount )
{
	std::sort(group.begin(), group.end());
	// Use std::unique to remove adjacent duplicates and count them
	auto it = std::unique(group.begin(), group.end());
	duplicateCount = std::distance(it, group.end());
	// Erase the duplicate contacts
	group.erase(it, group.end());
}