#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>


inline std::string input() {
	std::string str = " ";
	std::cin >> str;
	return str;
}


double parse(std::string str) {
	double binary = 0;
	binary = atof(str);
	return binary;
}


int convert_to_decimal(int binary) {
	int decimal = 0, remainder = 0;
	while (binary > 0) {
		remainder = binary%10;
		binary = binary/10;
		decimal = decimal*(pow(remainder));
	}
	return decimal;
}


bool chake(std::string str) {
	bool _True = false;
	for(int i = 0; i < str.length(); i++) {
		if (str[i] >= 48 && str[i] <= 49) _True = true;
		else {
			_True = false;
			break;
		}
	}
	return _True;
}


int main(int argc, char **argv) {
	
	std::string str = "";
	str = input();
	if (chake(str)) {
		std::cout << "done: ";
		int binary = parse(str);
		int decimal = convert_to_decimal(binary);
		std::cout << decimal;
	}
	else std::cerr << "wrong input";
	
	return EXIT_SUCCESS;
}
