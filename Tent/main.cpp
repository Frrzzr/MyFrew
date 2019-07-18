#include <iostream>
#include <stdlib.h>
#include "tent.h"

int main(int _argc, char**_argv) {
    
    rangeRing<int> ring(5, 34);
    ring.add(35);
    ring.add(37);
    ring.add(35);
    ring.add(37);
    ring.add(40);
    ring.add(37);
    for (signed int i = 0; i < 5; i++)
        std::cout << ring.get(i) << std::endl;
    
    rangeRing<std::string> ringlist(5, "Frew");
    ringlist.add("eden");
    ringlist.add("Frew");
    ringlist.add("Trow");
    ringlist.add("frozen");
    ringlist.add("cloud");
    ringlist.add("Frrzzr");
    for (signed int i = 0; i < 5; i++)
        std::cout << ringlist.get(i) << std::endl;
    
    return EXIT_SUCCESS;
}
