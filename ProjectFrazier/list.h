#include <iostream>
#include <string>


#ifndef LIST_H
#define LIST_H


#define _Head 0
#define _Last -1


class List {

	private:char *word;
			int index;
		    List *next;
			List *previous;
			void operator<<(std::string word);
	public: void append(char* wd);// {};// = 0; 
			void print(int position = 0);
			List();
			List(int, char *);
			//void setListValue(int inx, std::string wd, List *next) {}
};


static List *HEAD = NULL;
static List *CURRENT = NULL;
static List *LAST = NULL;


#endif //LIST_H