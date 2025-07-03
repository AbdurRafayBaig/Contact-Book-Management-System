# Contact-Book-Management-System
This Contact Book Management System is a C++ application built using Object-Oriented Programming concepts. It allows users to store, manage, and search personal contacts through a terminal-based interface. Each contact includes information like first name, last name, mobile number, email, and a complete home address.

**Class Structure**
**Address Class**
This class handles all address-related data, including house number, street, city, and country. It supports user input, data comparison, file saving and loading, and letter-based search functionality that highlights matched characters in the terminal using ANSI color codes.

**Contact Class**
Derived from the Address class, it adds personal contact details such as names, phone numbers, and emails. The class includes functions to add, display, compare, delete, and search contacts. Operator overloading is used for comparison and sorting logic, making the system more robust.

**ContactsBook Class**
This is the main controller class of the application. It manages an array of contacts using dynamic memory allocation. The system resizes the array when needed, merges duplicate contacts, updates existing ones, and removes entries. It also provides sorting options and supports saving and loading the contact list from a file for persistent storage.
**
SearchHistory Class**
This class records the user’s search queries by name, phone number, or address. These records are saved into a file and can be retrieved later for reference. It enhances the usability by keeping track of search behavior.

**Key Features**
Structured use of Object-Oriented Programming
Dynamic memory allocation using pointers
File input and output using standard C++ streams
Console-based search with colored character highlighting
Support for adding, editing, deleting, sorting, and merging contacts
Modular design with clear separation of functionalities

**Use Case**
This project is ideal for beginners and students learning core C++ concepts such as classes, inheritance, file handling, and dynamic memory management in a real-world scenario.


