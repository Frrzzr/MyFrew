#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "list.h"
#include "SourceRead.h"

/*
	_Head = 0 leting the print fun() to start from the top of the begining
	_Last = -1 >> >> >> >> >> >> >> >> >> >> >> >> >> last >> >> >> >> >> >>
*/

template <class Type>
Type generic_calculator(Type &one, Type &two) {
	return one + two;
}

static std::string cc = "C:\\Users\\Kiot\\Documents\\Visual\ Studio\ 2012\\Projects\\WindowsFormsApplication1\\WindowsFormsApplication1\\Form1.Designer.cs";


int main(int argc, char **argv) {

	//int x = 10;
	//x = generic_calculator(x, x);
	//std::string str = "Frazier";
	//str = generic_calculator(str, str);
	//float f = 10.56f;
	//f = generic_calculator(f, f);
	//std::cout << x << str << f << std::endl;


	File_Open *Frozen = new File_Open(cc);
	List lost;// = new List();
	Frozen->File_To_String(lost);

	system("pause");
	return EXIT_SUCCESS;
}