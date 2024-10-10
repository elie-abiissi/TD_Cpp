#include "my_class.h"
#include <iostream>
using namespace std;

my_class::my_class() : message("") {} 

my_class::my_class(const string& _message) : message(_message) {}

void my_class::print_my_element() const {
    std::cout << message << std::endl;
}
