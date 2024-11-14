#include "headers/pokemon_card.h"

PokemonCard::PokemonCard(const string& name, const string& type, const string& family,
                         int evolution, int maxHP, 
                         const vector<tuple<int, int, string, int>>& atk)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution),
      maxHP(maxHP), hp(hp), attacks(atk) {hp = maxHP;}

PokemonCard::PokemonCard(const string& name, const string& type, const string& family, int evolution, int maxHP, 
                int attack1Cost, const string& attack1Desc, int attack1Damage,
                int attack2Cost, const string& attack2Desc, int attack2Damage)
        : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution),
          maxHP(maxHP), hp(hp) 
    {
        attacks.push_back(make_tuple(attack1Cost, 0, attack1Desc, attack1Damage));
        attacks.push_back(make_tuple(attack2Cost, 0, attack2Desc, attack2Damage));

    }

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name: " << cardName 
         << ", Type: " << pokemonType 
         << ", Evolution Level: " << evolutionLevel 
         << " of the family \"" << familyName 
         << ", HP: " << maxHP << "\"" <<endl;

    cout << "Attacks:\n";
    int attackNumber = 0;
    for (const tuple<int, int, string, int>& attack : attacks) {
        int energyCost, currentEnergyCost, damage;
        string description;
        tie(energyCost, currentEnergyCost, description, damage) = attack;

        cout << "Attack #" << attackNumber++ << ":\n";
        cout << "Attack cost: " << energyCost << "\n";
        cout << "Attack current energy storage: " << currentEnergyCost << "\n";
        cout << "Attack description: " << description << "\n";
        cout << "Attack damage: " << damage << "\n";
    }
}

void PokemonCard::addActualAttackCost() {
    for (auto& attack : attacks) {
        cout << "test " << get<2>(attack) << endl;
        get<1>(attack)++; 
    }
}


string PokemonCard::getPokemonType() const {
    return pokemonType;
}

string PokemonCard::getFamilyName() const {
    return familyName;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

int PokemonCard::getCurrentHP() const {
    return hp;
}

void PokemonCard::heal() {
    hp = maxHP;
}

vector<tuple<int, int, string, int>>& PokemonCard::getAttacks() {
        return attacks;
    }



void PokemonCard::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}