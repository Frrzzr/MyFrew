#include <iostream>
#include <stdlib.h>
#include <string>

#include "list.h"


//static int index = 0;
//static List *HEAD = NULL;
//static List *CURRENT = NULL;


List::List(): word("0"), index(0), next(NULL) {}


void List::print(int position) {
	if (position == _Head) {
		CURRENT = HEAD;
		while (CURRENT != NULL) {
			std::cout << CURRENT->index << " ";
			std::cout << CURRENT->word << std::endl;
			CURRENT = CURRENT->next;
		}
	}
	else if (position == _Last) {
		CURRENT = LAST;
		while (CURRENT != NULL) {
			std::cout << CURRENT->index << " ";
			std::cout << CURRENT->word << std::endl;
			CURRENT = CURRENT->previous;
		}
	}
	else {std::cerr << "under construction check"
		"out my GitHub repo for update to come out";
		print(_Head);
	}
	std::cout << " -- end of list -- " << std::endl;
}


void List::append(char* wd) {
	List *LIST = new List();
	LIST->index += index;
	LIST->word = wd;
	LIST->next = HEAD;
	HEAD = LIST;
	index += 1;
}