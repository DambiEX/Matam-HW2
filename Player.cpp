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

Player::Player(char* Name, int MaxHP, int Force){
    name = Name;
    maxHP = MaxHP;
    HP = maxHP;
    force = Force;
    level = 1;
    coins = 0;
}

Player::Player(const Player &) {} //TODO: implement

Player::~Player() {} //TODO: implement

void Player::printInfo() const {
    printPlayerInfo(name, level, force, HP, coins);
}

void Player::levelUP() {
    if (level >= 10)
    {
        return;
    }
    else
    {
        level++;
    }
}

int Player::getLevel() const {
    return level;
}

void Player::buff(int amount) {
    //TODO: handle force max size
    force++;
}

void Player::heal(int amount) {
    HP = fill(maxHP, HP, amount, UPPER_BOUND);
}

void Player::damage(int amount) {
    HP = fill(0, HP, amount, LOWER_BOUND);
}

bool Player::isKnockedOut() const {
    if (HP <= 0){
        return true;
    }
    else{
        return false;
    }
}

void Player::addCoins(int amount) {
    assert(amount > 0);
    coins+=amount;
}

bool Player::pay(int amount) {
    if (coins < amount)
    {
        return false;
    }
    else
    {
        coins-=amount;
        return true;
    }
}

int Player::getAttackStrength() const {
    return level+force;
}











