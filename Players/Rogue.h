//
// Created by Tal on 6/10/2022.
//
#include "Player.h"
#include "../utilities.h"
#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

class Rogue : public Player{
public:
    Rogue (const std::string &name, const std::string &type) :
        Player(name, type){}
    Rogue(const Rogue& rogue) = default;
    Rogue& operator=(const Rogue& rogue) = default;
    ~Rogue() override = default;
    void heal(int HPToAdd) override;
    void addCoins(int coinsToAdd) override;
    int getAttackStrength() const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_ROGUE_H
