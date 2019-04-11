#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "SourceRead.h"
#include "list.h"


//char * cc = "C:\\Users\\Kiot\\Documents\\Visual\ Studio\ 2012\\Projects\\WindowsFormsApplication1\\WindowsFormsApplication1\\Form1.Designer.cs";


File_Open::File_Open(std::string nFile): File_Name(nFile) {
	File.open(File_Name, std::ios::in);
	if (!File || File.fail()) {
		std::cerr << "error while opening file \n"
			" i am afraid of for any data lost if" << std::endl;
		exit(1);
	}
}


std::string File_Open::File_To_String(List &lost) {
	char *word = " ";
	while (!File.eof()) {
		File >> word;
		word += (" ";
		lost.append(word);
	}
	return "";
}


//List *File_Open::toList() {
//	List *lost = new List();
//
//	const std::string Fall = File_To_String();
//	// for each word separeted by space loop through and append it to the list
//	while (str) {
//		lost->append((const char *));
//	}
//	return lost;
//}