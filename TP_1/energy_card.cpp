#include "headers/energy_card.h"

EnergyCard::EnergyCard(const string& type) : Card("Energy"), energyType(type) {}

void EnergyCard::displayInfo() const {
    cout << "Card Name: " << cardName << "\n";
    cout << "Energy Type: " << energyType << "\n";
}

string EnergyCard::getEnergyType() const {
    return energyType;
}