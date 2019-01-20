#include <iostream>
#include <algorithm>



int length(char *str) {
    int size = 0;
    while (*str != NULL) {
        size++;
        str++;
    }
    return size;
}


char *reverse(char *str) {
   int size = length(str);
   for (int I = 0; I < size; I++) {
       char *tmp = str[I];
       str[I] = str[size - I];
       str[size -I] = tmp;
   }
}


int main() {
    char *str = (char*)" ", tmp;
    str = gets(str);
    tmp = str;
    str = reverse(str);
    if (str == tmp) std::cout << " palindrome ";
    else std::cout << " Not Palindrome ";
    
}
