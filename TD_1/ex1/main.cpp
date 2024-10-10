#include <iostream>
#include "main.h"
#include "my_class.h"
using namespace std;

void printMessage(string& message){
    cout << message << endl;
}

void printHello(string& message){
    cout << message << endl;
}

int main(){
    cout<<"Hello World!"<<endl;

    string message = "Hello World!";
    printMessage(message);
    printHello(message);

    my_class cl1;
    cl1.print_my_element();

    my_class cl2(message);
    cl2.print_my_element();

    return 0;
}