//
// Created by Tal on 6/10/2022.
//
#include "Player.h"
#include "../utilities.h"
#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

class Fighter : public Player{
public:
    Fighter (const std::string &name, const std::string &type) :
            Player(name, type){}
    Fighter(const Fighter& fighter) = default;
    Fighter& operator=(const Fighter& fighter) = default;
    ~Fighter() override = default;
    void heal(int HPToAdd) override;
    void addCoins(int coinsToAdd) override;
    int getAttackStrength() const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_FIGHTER_H
