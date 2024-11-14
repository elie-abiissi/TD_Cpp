#include "headers/player.h"

Player::Player(const string& name, const vector<PokemonCard*>& actCards, const vector<Card*>& benCards)
    : playerName(name), actionCards(actCards), benchCards(benCards) {}

Player::Player(const string& name) : playerName(name) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemon) {
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + index);
            cout << playerName << " is activating a Pokemon Card: " << pokemon->getName() << "\n";
        } else {
            cout << "This card is not a Pokemon card\n";
        }
    } else {
        cout << "Invalid index in bench cards\n";
    }
}

void Player::attachEnergyCard(int actionIndex, int energyIndex) {
    if (actionIndex >= 0 && actionIndex < actionCards.size() && energyIndex >= 0 && energyIndex < benchCards.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
        if (energyCard) {
            actionCards[actionIndex]->addActualAttackCost();
            cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType()
                      << " to the Pokemon " << actionCards[actionIndex]->getName() << "\n";
            benchCards.erase(benchCards.begin() + energyIndex);
        } else {
            cout << "The card at index " << energyIndex << " is not an Energy card\n";
        }
    } else {
        cout << "Invalid index for attaching the Energy card\n";
    }
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":\n";
    for (const Card* card : benchCards) {
        if (const TrainerCard* trainerCard = dynamic_cast<const TrainerCard*>(card)) {
            trainerCard->displayInfo();
        } else if (const EnergyCard* energyCard = dynamic_cast<const EnergyCard*>(card)) {
            energyCard->displayInfo();
        } else if (const PokemonCard* pokemonCard = dynamic_cast<const PokemonCard*>(card)) {
            pokemonCard->displayInfo();
        }
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":\n";
    for (const PokemonCard* card : actionCards) {
        if (card) {
            card->displayInfo();
        }
    }
}

void Player::useTrainer(int index) {
    if (index >= 0 && index < benchCards.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[index]);
        if (trainerCard) {
            cout << playerName << " is using the Trainer Card to \"" 
                 << trainerCard->getTrainerEffect() << "\"" << endl;
            trainerCard->healAllYourActionPokemon(actionCards);
            benchCards.erase(benchCards.begin() + index);
        } else {
            cout << "The card at index " << index << " is not a Trainer card" << endl;
        }
    } else {
        cout << "Invalid index for Trainer card" << endl;
    }
}


void Player::attack(int actionIndex, int attackIndex, Player& targetPlayer, int targetActionIndex) {
    if (actionIndex >= 0 && actionIndex < actionCards.size()) {
        PokemonCard* attackingPokemon = actionCards[actionIndex];

        cout << "Only " << attackingPokemon->getAttacks().size() << " attacks exist." << endl;
        if (attackIndex >= 0 && attackIndex < attackingPokemon->getAttacks().size()) {
            tuple<int, int, string, int>& attackDetails = attackingPokemon->getAttacks()[attackIndex];
            int energyCost = get<0>(attackDetails);
            int currentEnergyCost = get<1>(attackDetails);
            string attackDesc = get<2>(attackDetails);
            int damage = get<3>(attackDetails);

            if (currentEnergyCost >= energyCost) {
                PokemonCard* targetPokemon = targetPlayer.actionCards[targetActionIndex];

                cout << this->playerName << " attacking " << targetPlayer.playerName
                     << "'s Pokemon " << targetPokemon->getName() 
                     << " with the Pokemon " << attackingPokemon->getName() 
                     << " using its attack: " << attackDesc << endl;

                targetPokemon->takeDamage(damage);
                
                cout << "Reducing " << damage << " from " << targetPlayer.playerName 
                     << "'s Pokemon's HP." << endl;

                if (targetPokemon->getCurrentHP() > 0) {
                    cout << "Pokemon " << targetPokemon->getName() << " is still alive!" << endl;
                } else {
                    cout << targetPokemon->getName() << " has fainted!" << endl;
                }

                currentEnergyCost -= energyCost;
            } else {
                cout << attackingPokemon->getName() << " does not have enough energy to use " << attackDesc << "!" << endl;
            }
        } else {
            cout << "Invalid attack index." << endl;
        }
    } else {
        cout << "Invalid action index." << endl;
    }
}

