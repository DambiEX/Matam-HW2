//TODO: code conventions for class member names. camelcase?

#ifndef MATAM_HW2_PLAYER_H
#define MATAM_HW2_PLAYER_H

#define UPPER_BOUND 1
#define LOWER_BOUND -1

class Player {
    //"private:" is automatic with classes

    char* name;
    int level;
    int force, maxHP, HP, coins;
public:
    Player(char* Name, int MaxHP = 100, int Force = 5); //constructor //TODO: conventions for constructor parameters
    Player(const Player&); //copy constructor
    ~Player(); // destructor

    void printInfo() const;
    int getLevel() const;
    void levelUP();
    void buff(int amount);
    void heal(int amount);
    void damage(int amount);
    bool isKnockedOut() const;
    void addCoins(int amount);
    bool pay(int amount);
    int getAttackStrength() const;
};


#endif //MATAM_HW2_PLAYER_H
