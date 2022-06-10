//
// Created by Tal on 6/10/2022.
//
#include "Player.h"
#include "utilities.h"
#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

class Fighter : public Player{

public:
    Fighter (const std::string &name, int HP=100, int force=5) :
            Player(name, HP, force){}
    Fighter(const Fighter& fighter) = default;
    Fighter& operator=(const Fighter& fighter) = default;
    ~Fighter() override = default;
    std::ostream& operator<<(std::ostream& os) override;
    void heal(int HPToAdd) override;
    void addCoins(int coinsToAdd) override;
    int getAttackStrength() const override;
};

#endif //EX4_FIGHTER_H
