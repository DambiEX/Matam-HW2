//TODO: code conventions for class member names. camelcase?

#ifndef MATAM_HW2_PLAYER_H
#define MATAM_HW2_PLAYER_H


class Player {
    //"private:" is automatic with classes

    char* name;
    int Level;
    int force, maxHP, HP, coins;
public:
    Player(char* Name, int MaxHP = 100, int Force = 5); //constructor //TODO: conventions for constructor parameters
    Player(const Player&); //copy constructor
    ~Player(); // destructor

    void printInfo();
    int getLevel();
    void buff(int amount);
    void heal(int amount);
    void damage(int amount);
    bool isKnockedOut();
    void addCoins();
    bool pay(int amount);
    int getAttackStrength();
};


#endif //MATAM_HW2_PLAYER_H
