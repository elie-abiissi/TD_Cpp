#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "card.h"

using namespace std;

class PokemonCard : public Card {
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks;

public:
    PokemonCard(const string& name, const string& type, const string& family,
                int evolution, int maxHP,
                const vector<tuple<int, int, string, int>>& atk);

    PokemonCard(const string& name, const string& type, const string& family, int evolution, int maxHP, 
                int attack1Cost, const string& attack1Desc, int attack1Damage,
                int attack2Cost, const string& attack2Desc, int attack2Damage);

    void displayInfo() const override;
    void addActualAttackCost();
    string getPokemonType() const;
    string getFamilyName() const;
    void takeDamage(int);
    vector<tuple<int, int, string, int>>& getAttacks();
    int getEvolutionLevel() const;
    int getMaxHP() const;
    int getCurrentHP() const;
    void heal();
};

#endif