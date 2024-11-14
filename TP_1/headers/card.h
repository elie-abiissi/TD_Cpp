#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
protected:
    string cardName;

public:
    Card(const string& name) : cardName(name) {}
    virtual void displayInfo() const = 0;
    virtual ~Card() {}
    string getName() const;
};

#endif