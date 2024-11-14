#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include "card.h"
#include "pokemon_card.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrainerCard : public Card {
private:
    string trainerEffect;

public:
    TrainerCard(const string& trainerName);
    TrainerCard(const string& name, const string& effect);
    void healAllYourActionPokemon(vector<PokemonCard*>& activePok) const;
    string getTrainerEffect() const;
    void displayInfo() const override;
};

#endif
