//
// Created by Tal on 6/10/2022.
//
#include <string>
#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

class Player{

protected:
    std::string m_name;
    int m_coins;
    int m_force;
    int m_HP;
    int m_level;

public:
    Player(const std::string name, int HP=100, int force=5);
    Player(const Player& player) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& player) = default;
    //virtual void printInfo() const = 0;
    void levelUp();
    int getLevel() const;
    void buff(int forceToAdd);
    virtual void heal(int HPToAdd) = 0;
    void damage(int HPToRemove);
    bool isKnockedOut() const;
    virtual void addCoins(int coinsToAdd) = 0;
    bool pay(int coinsToPay);
    virtual int getAttackStrength() const = 0;
};

#endif //EX4_PLAYER_H
