#ifndef MATAM_HW2_PLAYER_H
#define MATAM_HW2_PLAYER_H

#define UPPER_BOUND 1
#define LOWER_BOUND -1

class Player {
public:

    void printInfo() const;
    int getLevel() const;
    void levelUp();
    void buff(int amount);
    void heal(int amount);
    void damage(int amount);
    bool isKnockedOut() const;
    void addCoins(int amount);
    bool pay(int amount);
    int getAttackStrength() const;

    explicit Player(const char* name, int maxHP = 100, int force = 5);
    Player(const Player&) = default;
    ~Player() = default;

private:
    const char* m_name{};
    int m_level{};
    int m_force{}, m_maxHP{}, m_HP{}, m_coins{};
};


#endif //MATAM_HW2_PLAYER_H
