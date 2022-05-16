#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include "Player.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);
    Mtmchkin(const Mtmchkin&) = default;
    ~Mtmchkin() = default;

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();

    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;

    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;



private:
    const int m_cards_num;
    Player m_player;
    GameStatus m_status;
    const Card* m_cards;
    int m_cards_index;

    /*
     * Increments m_cards_index. If it reached the end of the deck, resets the index to 0.
     */
    void increment_cards_index();

    /*
     * Checks if the Player is dead of at the maximum level, and updates the game status accordingly.
     */
    void updateGameStatus();
};


#endif //EX2_GAME_H
