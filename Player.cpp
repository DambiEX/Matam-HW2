//TODO: figure out strings as arguments to functions.

#include "Player.h"

Player::Player(char* Name, int MaxHP, int Force){
    name = Name;
    maxHP = MaxHP;
    HP = maxHP;
    force = Force;
    Level = 1;
    coins = 0;
}

Player::Player(const Player &) {} //TODO: implement

Player::~Player() {} //TODO: implement

void Player::printInfo() {

}


int Player::getAttackStrength() {
    return 0;
}

bool Player::pay(int amount) {
    return false;
}

void Player::addCoins() {

}

bool Player::isKnockedOut() {
    return false;
}

void Player::damage(int amount) {

}

void Player::heal(int amount) {

}

void Player::buff(int amount) {

}

int Player::getLevel() {
    return 0;
}

