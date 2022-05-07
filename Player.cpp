//TODO: figure out strings as arguments to functions.
//TODO: edge cases on all functions: inputs 0, NULL, negative. etc.

#include "Player.h"
#include "utilities.h"
#include <cassert> //TODO: use "assert" instead? which library are we allowed to use?


static int fill(int threshold, int attribute, int amount, int direction){ //TODO: better parameter names
    assert(amount >= 0); //TODO: maybe handle edge cases instead of asserting?
    int change = amount*direction;
    if ((attribute + change)*direction > threshold)
    {
        return threshold;
    }
    else
    {
        return attribute+change;
    }
}

Player::Player(char* name, int maxHP, int force){
    m_name = name;
    m_maxHP = maxHP;
    m_HP = m_maxHP;
    m_force = force;
    m_level = 1;
    m_coins = 0;
}

Player::Player(const Player &) {} //TODO: implement

Player::~Player() {} //TODO: implement

void Player::printInfo() const {
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}

void Player::levelUP() {
    if (m_level >= 10)
    {
        return;
    }
    else
    {
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int amount) {
    //TODO: handle force max size
    m_force++;
}

void Player::heal(int amount) {
    m_HP = fill(m_maxHP, m_HP, amount, UPPER_BOUND);
}

void Player::damage(int amount) {
    m_HP = fill(0, m_HP, amount, LOWER_BOUND);
}

bool Player::isKnockedOut() const {
    if (m_HP <= 0){
        return true;
    }
    else{
        return false;
    }
}

void Player::addCoins(int amount) {
    assert(amount > 0);
    m_coins+=amount;
}

bool Player::pay(int amount) {
    if (m_coins < amount)
    {
        return false;
    }
    else
    {
        m_coins-=amount;
        return true;
    }
}

int Player::getAttackStrength() const {
    return m_level+m_force;
}











