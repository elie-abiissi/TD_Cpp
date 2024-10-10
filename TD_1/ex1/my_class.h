#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>
using namespace  std;


class my_class {
private:
    string message;

public:
    my_class();
    my_class(const string&); 

    void print_my_element() const;
};

#endif
