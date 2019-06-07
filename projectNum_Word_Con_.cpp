/*
 * 
 *
 *
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>


static const std::string ones[20] = {	
	"zero", "one", "two", "three", "four", "five",
	 "six", "seven", "eight", "nine", "ten", "eleven",
	 "tweleve", "thirteen", "fourteen", "fifteen", "sixteen",
	 "seventeen", "eighteen", "nineteen"
	};


static const std::string tens[8] = { "twenty", "thirty", "fourty", "fifty", "sixty",
	 "seventy", "eighty", "ninety"
	};

void effect() {

   	system("color 05");
	std::cout <<"\n\n\n\t\t $$           $$    $$$$$     $$         $$$$$     $$$$$      $$         $$     $$$$$\n";
	std::cout <<"\t\t  $$    $    $$     $$        $$        $$        $$   $$     $$ $$   $$ $$     $$\n";
    	std::cout <<"\t\t   $$  $$$  $$      $$$$$     $$        $$        $$   $$     $$   $$$   $$     $$$$$\n";
    	std::cout <<"\t\t    $$$   $$$       $$        $$        $$        $$   $$     $$    $    $$     $$\n";
	std::cout <<"\t\t     $$   $$        $$$$$     $$$$$$     $$$$$     $$$$$      $$         $$     $$$$$\n";
	std::cout <<"\n\n\n\tThis is a simple number to word conversion system\n " << std::endl;
	Sleep(3000);
	system("cls");
	//system("color 07");
	std::cout << std::endl;
}

void memdata() {
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
    std::string str = "     ---Members of the group---\n\n---Name---------------ID------\n1: GEBEYAW DEJEN  "  
    		"AKU1001152\n2: HABTAMU FENTAHUN   AKU1001132\n3: HABTAMU RAYA       AKU1001303\n4: GRMAY DESTA    "
        	"AKU1001138\n5: HABIB              AKU100\n\n";
    memData << str;
    memData.close();
    
    rmemData.open("member.txt",std::ios::in);
    
    if (!rmemData.is_open()) {
			std::cerr << "error occured while opening the file!\n";
               std::cout << "  ---Members of the group---\n1: ";
			exit(1);
		}
    
    while (!rmemData.eof()) {
        getline(rmemData, str);
        std::cout << str << std::endl;
    }
    std::cout << std::endl;
    
		
}

int main () {
	
	
	//effect();
	int num, leftdigit, rightdigit, midledigit, temp, secondDigit, thirdDigit, fourthDigit, fifthDigit;
	std::fstream history;
	history.open("history.txt", std::ios::app);
	
	if (history.fail()) std::cerr << "unaible to open the history.txt for history record method" << std::endl;
	
	
	for (int i = 0; i < 20; i++)  history << ones[i];

	for (int i = 0; i < 8; i++) history << tens[i];
	top:
	std::cout << "enter the number:\n" << std::endl;
	std::cin >> num;
	std::string str;

	if (num < 0) {
		str = "Negative ";
		num = -(num);
	}
	
	//else if (num == 0) str = "0";
	else str = " ";
	
	if(num <= -1000000 || num >= 1000000) std::cout << "the number must be between -100000 to 100000:  " << std::endl;
	
	else if (num >= 0 && num <= 19) std::cout << "the number you entred is: " << str << ones[num] << std::endl;
	
	else if(num >= 20 && num <= 99){
		leftdigit = num / 10;
		rightdigit = num % 10;
		std::cout << "the number you have entered is: " << str << tens[leftdigit-2];
		if (rightdigit != 0) std::cout << " " << ones[rightdigit] << std::endl;
	}
	
	
	else if(num >= 100 && num <= 999) {  // we need three variable
		
		leftdigit = num / 100; //std::cout << leftdigit << "\n";
		//temp = num % 100;
		midledigit = (num % 100) / 10; //std::cout << midledigit << "\n";
		rightdigit = num % 10;  //std::cout << rightdigit << "\n";
		std::cout << "the number you have entered is: " << str << ones[leftdigit] << " hundred ";
		if (midledigit == 1) std::cout << ones[midledigit + 10];
		else {
			if (midledigit != 0) std::cout << tens[midledigit - 2];
			if (rightdigit != 0) std::cout << " " << ones[rightdigit] << std::endl;
		}
	}
	
	
	else if(num >= 1000 && num <= 9999) { // we need four variable
		leftdigit = num / 1000; //std::cout << leftdigit << "\n";
		temp = num % 1000;
		secondDigit = (num % 1000) / 100; //std::cout << secondDigit << "\n";
		thirdDigit = (temp % 100) / 10; //std::cout << thirdDigit << "\n";
		rightdigit = temp % 10; //std::cout << rightdigit << "\n";
		std::cout << "the number you have entered is: " << str << ones[leftdigit] << " thousand "; 
		if (secondDigit != 0) std::cout << ones[secondDigit] << " hundred " ;
		if (thirdDigit == 1)
			std::cout << ones[thirdDigit + 10];
		else {
			if (thirdDigit != 0 ) std::cout<< tens[thirdDigit - 2];
			if (rightdigit != 0) std::cout  << " " << ones[rightdigit] << std::endl;
		}
	}
	
	
	else if(num >= 10000 && num <= 99999) { // we need five variable
		leftdigit = num / 10000; 
		temp = num % 10000;
		secondDigit = temp / 1000;
		temp = temp % 1000;
		thirdDigit =  temp / 100;
		temp %= 100; 
		fourthDigit = temp / 10;
		rightdigit = temp % 10;
		if (leftdigit != 1) {
			std::cout << "the number you have entered is: " << str << tens[leftdigit - 2] << " "; 
			if (secondDigit != 0) std::cout << ones[secondDigit];
		}
		else if (leftdigit == 1) {
			std::cout << "the number you have entered is: " << str << ones[leftdigit + (secondDigit + 9)] << " "; 
		}
		std::cout << " thousand ";
		if (thirdDigit != 0) std::cout << ones[thirdDigit] << " hundred ";
		if (fourthDigit == 1) {
			std::cout << ones[fourthDigit + 10];
		}
		else	{
			if (fourthDigit != 0) std::cout << tens[fourthDigit - 2];
			if (rightdigit != 0) std::cout << " " << ones[rightdigit] << std::endl;
		}
	}
	
	else if (num >= 100000 && num <= 999999) {
		leftdigit = num / 100000;
		temp = num % 100000;
		secondDigit = temp / 10000;
		temp = temp % 10000;
		thirdDigit =  temp / 1000;
		temp %= 1000; 
		fourthDigit = temp / 100; 
		temp %= 100;
		fifthDigit = temp / 10;
		rightdigit = temp % 10;
		
		std::cout << "the number you have entered is: " << str << ones[leftdigit] << " hundred ";
		
		if (secondDigit == 1) std::cout << ones[secondDigit + 10 + thirdDigit - 1] << " thousand ";
		else {
			if (secondDigit != 0) std::cout << tens[secondDigit - 2] << " ";
			else if (secondDigit == 0) std::cout << " thousand ";
		}
		if (secondDigit != 1) if (thirdDigit != 0) std::cout << ones[thirdDigit] << " thousand ";
		else std::cout << " thousand ";
		if (fourthDigit != 0) std::cout << ones[fourthDigit] << " hundred ";
		if (fifthDigit == 1) std::cout << ones[fifthDigit + 10];
		else {
			if (fifthDigit != 0) std::cout << tens[fifthDigit - 2] << " ";
			if (rightdigit != 0) std::cout << ones[rightdigit];
		}
	}
	
	for (int i = 0; ; i++) {
		std::string choice;
		head:
		std::cout << "\nDo you want to continue [y/n]: ";
		std::cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES")
			goto top;
		else if (choice == "N" || choice == "n" || choice == "no" || choice == "No" || choice == "NO") {
			memdata();
			return 0;
		}
		else { std::cout << "\nwe coundn't understand you try again[y/n]:"; goto head; }
		
	}
	system("pause");
}
