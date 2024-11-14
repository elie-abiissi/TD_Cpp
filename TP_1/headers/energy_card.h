#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "card.h"
#include <iostream>
#include <string>

using namespace std;

class EnergyCard : public Card {
private:
    string energyType;

public:
    EnergyCard(const string& type);
    void displayInfo() const override;
    string getEnergyType() const;
};

#endif