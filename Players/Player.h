//
// Created by Tal on 6/10/2022.
//
#include <string>
#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

class Player{

protected:
    std::string m_name;
    std::string m_type;
    int m_coins;
    int m_force;
    int m_HP;
    int m_level;

public:
    Player(const std::string &name, const std::string &type);
    Player(const Player& player) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& player) = default;
    void levelUp();
    int getLevel() const;
    int getCurrentHp() const;
    int getNumberOfCoins() const;
    void nerf(int forceToReduce);
    const std::string& getPlayerName() const;
    void buff(int forceToAdd);
    virtual void heal(int HPToAdd) = 0;
    void damage(int HPToRemove);
    bool isKnockedOut() const;
    virtual void addCoins(int coinsToAdd) = 0;
    bool pay(int coinsToPay);
    virtual int getAttackStrength() const = 0;
    const std::string& getType() const;

    virtual std::ostream& print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif //EX4_PLAYER_H
