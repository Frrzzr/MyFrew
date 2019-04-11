#include <iostream>
#include <stdlib.h>
#include <string>


#include "list.h"


#ifndef SOURCE_READ_H
#define SOURCE_READ_H


class File_Open {
	public:
		File_Open(std::string);
		List *toList();
		std::string File_To_String(List &);
	protected:
	private:
		std::fstream File;
		std::string File_Name;
};


#endif //SOURCE_READ_H