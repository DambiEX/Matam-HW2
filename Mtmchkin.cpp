//
// Created by PC on 6/5/2022.
//

#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) {
    m_player = Player(playerName); //TODO: implement copy constructor
    m_cards = cardsArray;
    m_cards_num = numOfCards;
    m_status = GameStatus::MidGame;
    m_cards_index = 0;
}

void Mtmchkin::playNextCard() {

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

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

void Mtmchkin::loopGame() {
    while(!isOver()){
        playNextCard();
    }

}

