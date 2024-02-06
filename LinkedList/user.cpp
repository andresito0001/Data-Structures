#include <iostream>
#include "GList.hpp"

int main(void) {
    GList<int> mylist = { 1,2,3,4,5 };
    
    std::cout << mylist.back() << ' ';

    mylist.pop_back();
    mylist.pop_back();


    std::cout << mylist.back();
    return 0;
}
