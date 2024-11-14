#include "headers/trainer_card.h"

TrainerCard::TrainerCard(const string& trainerName) : Card(trainerName), trainerEffect("heal all your action pokemon") {}
TrainerCard::TrainerCard(const string& name, const string& effect) : Card(name),trainerEffect(effect){}

void TrainerCard::healAllYourActionPokemon(vector<PokemonCard*>& activePok) const {
    for (PokemonCard* pokemon : activePok) {
        pokemon->heal();
    }
}

string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

void TrainerCard::displayInfo() const {
        cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << "\n";
    }