#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "pokemon_card.h"
#include "energy_card.h"
#include "trainer_card.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name, const vector<PokemonCard*>& actCards, const vector<Card*>& benCards);
    Player(const string& name);

    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int actionIndex, int energyIndex);
    void displayBench() const;
    void displayAction() const;
    void useTrainer(int index);
    void attack(int actionIndex, int attackIndex, Player& targetPlayer, int targetActionIndex);
};

#endif
