//TODO: code conventions for class member names. camelcase?

#ifndef MATAM_HW2_PLAYER_H
#define MATAM_HW2_PLAYER_H


class Player {
    //"private:" is automatic with classes

    char* name;
    int Level;
    int force, maxHP, HP, coins;
public:
    Player(int Force); //constructor
    Player(const Player&); //copy constructor
    ~Player(); // destructor
};


#endif //MATAM_HW2_PLAYER_H
