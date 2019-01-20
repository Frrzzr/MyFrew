/*
 *  we recommend you to use visual studio
 *  to access all the feature of this programming
 *  please don't compile this source code where it is found  
 *  inorder to avoid creating and reading permission
 *  make your console width size to 300 to get clear image   
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#define MAX_V  25

// structing a contact to hold name and phone number
 
struct contact {
	char firstName[MAX_V], lastName[MAX_V],  number[MAX_V];
}rec;

bool fact, isFound = false;

/* This program contain about 5 functions
 *
 * contactAdd
 * contactUpdate
 * contactList
 * searchContact
 * memdata
 */
bool searchContact ();
void delet();
void contactAdd () { // adding a new record
	std::string ch; char m = 'A';
    //contact rec;
    
    std::fstream data;

	data.open("phone_book.txt", std::ios::app);

		time_t t = time(0);
		struct tm * now = localtime(&t);


		if (data.fail()) { std::cerr << "Error occured while opening:"; exit(1);}

		data << "Date added " << now->tm_mday << "-" << (now->tm_mon + 1) << "-" << (now->tm_year + 1900) << "\n";



			do {
				int n = 1;
     
		
				data << m << ", -------------------------------------------------\n";
				std::cout << "Go head enter the first name: " ; std::cin >> rec.firstName;
				data << n << ": " << rec.firstName << std::endl; n++;
				std::cout << "Enter last name: "; std::cin >> rec.lastName;
				data << n << ": " <<  rec.lastName << std::endl; n++;
				std::cout << "Enter mobile phone number: " << std::endl; std::cin >> rec.number;
				data << n << ": " << rec.number << std::endl;
		
				//top:
				for (int i = 0;;i++) {
						std::cout << "Need more record enter (y\\n): "; std::cin >> ch;
					if (ch != "y" && ch != "n" && ch != "Y" && ch != "N") {
						std::cerr << "\nwe couldn't understand you!!!. Try again\n";
         
					}
					else break;
				}
				system("cls");
				//if (ch == 'y' || ch == 'Y' || ch =='n' || ch == 'N' ) { std::cout << "Invalid input\n"; goto top;}
				n++;m++;
			} while (ch == "y" || ch == "Y" /* || ch =='n' || ch == 'N'*/);

    system("cls");
	data.close();
}
void contactUpdate () { // deleting and changing 
	std::string str;
	std::cout << "Update means either deleting or writting on an existing record\n"
			  << "First we wnat to be sure about your record is in the list or not!\n"
			  <<  "type lower case [delete\\update]: "; std::cin >> str;
	if (str == "delete")
		delet();
	Sleep(5000);
	system ("cls");
	/*static_cast<bool>(fact)*/fact = searchContact();

	if (fact)
		std::cout << "We are good to go\n\n";
	else 
		std::cout << "Cano't update this contact\n\n";
}
void contactList () { // printing the whole recorded data
     std::fstream data;
     std::string str = "";
     
	 data.open("phone_book.txt", std::ios::in);
	
	  if (data.fail()) { std::cerr << "Error occured while opening the file:"; exit(1);}
		//rdata.read((char*) & rec, sizeof(rec));
	 while (!data.eof()) {
		getline(data, str);
		std::cout << str << std::endl;
			/*if (!data.eof()) { 
				std::cout << rec.firstName;
				std::cout << rec.lastName;
				std::cout << rec.number;
			}*/
	}

    data.close();

}
bool searchContact () {

	char str[MAX_V];
	std::fstream search;
	//bool isFound = false;

	search.open("phone_book.txt", std::ios::in);
	std::cout  << "Enter the first name: ";
	std::cin >> str; std::cout << "wait while searching for --<< "; 
	system("color 02"); 
	std::cout << str ; 
	system("color 07"); 
	std::cout << " >>-- :" ;

	search.seekg(0, std::ios::beg);

	while (!search.eof()) {
		search >> rec.firstName;
		if (int(strcmp(rec.firstName, str)) == 0) {
			isFound = true;
			break; // no need to continue.
		}
	}
	search.read((char*) &rec, sizeof(rec));
			if (isFound) {
				std::cout << "details are found " << rec.firstName //<< std::endl 
					      << /*rec.lastName //<< std::endl 
					      <</ rec.number <<*/ std::endl;
				return true;
			}
			else { std::cout << "record not found\n\n"; return false; }

			//for (int i = 1; i <= 3)

}
void delet() {
	std::fstream search;
	char str[25];
	std::string sd;
	std::cout << "Do you wnat to delete all record [y\\n]: "; std::cin >> sd;
	if (sd == "y") {
		std::cout << "cleaned";
		search.open("phone_book.txt", std::ios::out);
	}
	else {
		search.open("phone_book.txt", std::ios::app);
		search.seekg(0, std::ios::beg);
		std::cout << "Enter the first name to delete: ";
		std::cin >> str;
		while (!search.eof()) {
			search >> rec.firstName;
			if (int(strcmp(rec.firstName, str)) == 0) {
				isFound = true;
				search.write((char*) &rec, sizeof(rec));
				break; // no need to continue.
			}
		}
		if (isFound)
			std::cout << "record deleted.";
		else 
			std::cout << "record not deleted !";
	}
}
void memData () {
	/*
	*
	* Displaiying the member of the group
	* using file  handling method 
	* if error occured the member is printed normaly
	* by sending the string of member data to the console window
	* 
	*/ 


	std::fstream memData, rmemData;
		memData.open("member.txt",std::ios::out);

		if (memData.fail()) {
			std::cerr << "error occured while opening the file!\n";
			exit(1);
		}
    std::string str = "   ---Members of the group---\n\n---Name---------------ID------\n1: Frezer Yirga       AKU1001271\n2: Fentaw Tefera      AKU1001275\n3: Filmawit negasi    AKU100\n4: Fana Mehari        AKU1001374\n5: Ezana Mezgebe      AKU100\n\n";
    memData << str;
    memData.close();
    
    rmemData.open("member.txt",std::ios::in);
    
    if (!rmemData.is_open()) {
			std::cerr << "error occured while opening the file!\n";
            std::cout << "  ---Members of the group---\n1: Frezer Yirga\n2: Fentaw Tefera\n3: Filmawit negasi\n4: Fana Mehari\n5: Ezana Mezgebe\n\n";
			exit(1);
		}
    
    while (!rmemData.eof()) {
        getline(rmemData, str);
        std::cout << str << std::endl;
    }
    std::cout << std::endl;
    
			std::cout << "End of the program: Good bye.\n";
			std::cout << "We need your comment inorder to emprove our skill!\nThanks a lot.\n";

}
int main () {
	
	system("color 02");
	std::cout <<" @@           @@    @@@@@@    @@         @@@@@     @@@@@      @@         @@     @@@@@@\n";
	std::cout <<"  @@    @    @@     @@        @@        @@        @@   @@     @@ @@   @@ @@     @@\n";
    std::cout <<"   @@  @@@  @@      @@@@@     @@        @@        @@   @@     @@   @@@   @@     @@@@@\n";
    std::cout <<"    @@@   @@@       @@        @@        @@        @@   @@     @@    @    @@     @@\n";
	std::cout <<"     @@   @@        @@@@@@    @@@@@@     @@@@@     @@@@@      @@         @@     @@@@@@\n";
	Sleep(2000);
	system("cls");
	system("color 07");
	std::cout << std::endl;

	// memory managment is need here
	std::string choice;
	// requiest a user (informing about what to be done here 
	std::cout <<"";
	std::cout << "\t---------------------------------"
			  <<"\n\t\aPlease enter your choice numbers \n\trecommended " 
				   << "for this sessiion.\n\t---------------------------------" << std::endl;
				 foo:
	std::cout << "\t1: To add a new record\n\t2: To updating existing recorded data" 
			  << "\n\t3: To list all recorded phone diary \n\t4: To search a recorded data \n\t5: To exit and list members \n\t";
	// std::cin >> choice;
  
	if (std::cin >> choice, choice != "1" && choice != "5" && choice != "2" && choice != "3" && choice != "4") { 
		system("cls");
		std::cout << "("<< choice<< ")" <<" Invalid input, Try again:\n"; 
		goto foo;
	}
	else {
		/*clrscr();*/
		system ("cls");
			if (choice == "1") {
				contactAdd ();
				goto foo;
			}
			else if (choice == "2") {contactUpdate (); goto foo; }
			else if (choice == "3") {contactList (); goto foo; }
			else if (choice == "4") {searchContact (); goto foo; }
			else if (choice == "5") {memData (); return 0; }
								
		}
	//else goto foo;
}



