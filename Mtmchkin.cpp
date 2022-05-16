#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards)
<<<<<<< HEAD
        : m_cards_num(numOfCards), m_player(playerName) {
    const int INDEX_AT_BEGINNING=-1;
    m_status = GameStatus::MidGame;
    m_cards = cardsArray;
    m_cards_index = INDEX_AT_BEGINNING;
}

void Mtmchkin::updateGameStatus() {
    const int MAX_LEVEL = 10;
    if (m_player.isKnockedOut()) {
=======
                    : m_cards_num(numOfCards), m_player(playerName) {
    m_cards = new Card[numOfCards];
    m_status = GameStatus::MidGame;
    m_cards_index = 0;

    for (int i = 0; i < numOfCards; ++i) {
        m_cards[i] = cardsArray[i];
    }
}

Mtmchkin::~Mtmchkin() {
    delete m_cards;
}

void Mtmchkin::updateGameStatus(){
    if (m_player.isKnockedOut())
    {
>>>>>>> b1e2805ef25d669a385bc969fa6e303460a92651
        m_status = GameStatus::Loss;
    }
    if (m_player.getLevel() == MAX_LEVEL) {
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

bool Mtmchkin::isOver() const {
    if (getGameStatus() != GameStatus::MidGame) {
        return true;
    } else {
        return false;
    }
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

void Mtmchkin::increment_cards_index() {
    m_cards_index++;
    if (m_cards_index >= m_cards_num) {
        m_cards_index = 0;
    }
<<<<<<< HEAD
}
=======
}



>>>>>>> b1e2805ef25d669a385bc969fa6e303460a92651
