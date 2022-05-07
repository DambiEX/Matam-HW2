//
// Created by PC on 6/5/2022.
//

#include "Card.h"

Card::Card(CardType type, const CardStats &stats) {
    m_effect = type;
    m_stats = stats; //TODO: need to unpack pointer? or is this ok because its a reference?
}

void Card::applyEncounter(Player &player) const {

}

void Card::printInfo() const {

}

