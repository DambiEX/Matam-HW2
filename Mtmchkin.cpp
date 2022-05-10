//
// Created by PC on 6/5/2022.
//

#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards)
                    : m_cards_num(numOfCards), m_player(playerName) {

    m_cards = cardsArray;
    m_status = GameStatus::MidGame;
    m_cards_index = 0;
}

void Mtmchkin::playNextCard() {
    increment_cards_index();
    m_current_card = m_cards[m_cards_index];
    m_current_card.printInfo();
    m_current_card.applyEncounter(m_player); // TODO: pass by reference? is this already happening?
    m_player.printInfo();
    changeGameStatus(m_player);
}

bool Mtmchkin::isOver() {
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

void Mtmchkin::changeGameStatus(Player &player){
    if (player.getLevel()>=10){
        m_status=GameStatus::Win;
        return;
    }
    else if (player.getLevel()<=0){
        m_status=GameStatus::Loss;
        return;
    }
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

void Mtmchkin::loopGame() {
    while(!isOver()){
        playNextCard();
    }
}

void Mtmchkin::increment_cards_index() {
    m_cards_index++;
    if (m_cards_index >= m_cards_num)
    {
        m_cards_index = 0;
    }
}

