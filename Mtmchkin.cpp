//
// Created by PC on 6/5/2022.
//

#include "Mtmchkin.h"
#define MAX_LEVEL 10

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards)
                    : m_cards_num(numOfCards), m_player(playerName), m_cards(cardsArray){
    m_status = GameStatus::MidGame;
    m_cards_index = 0;
}

//Mtmchkin::Mtmchkin(const Mtmchkin& other) : m_cards_num(other.m_cards_num), m_player(other.m_player) {
//
//}



void Mtmchkin::updateGameStatus(){
    if (m_player.isKnockedOut())
    {
        m_status = GameStatus::Loss;
    }
    if (m_player.getLevel() == MAX_LEVEL)
    {
        m_status = GameStatus::Win;
    }
}

void Mtmchkin::playNextCard() {
    increment_cards_index();
    if (m_cards_num > 0)
    {
        Card current_card(m_cards[m_cards_index]);
        current_card.printInfo();
        current_card.applyEncounter(m_player);
    }
    updateGameStatus();
    m_player.printInfo();
}

bool Mtmchkin::isOver() const{
    GameStatus status = getGameStatus();
    if (status == GameStatus::Win || status == GameStatus::Loss)
    {
        return true;
    }
    else
    {
        return false;
    }
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

void Mtmchkin::increment_cards_index() {
    m_cards_index++;
    if (m_cards_index >= m_cards_num)
    {
        m_cards_index = 0;
    }
}


