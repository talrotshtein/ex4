//
// Created by Tal on 6/10/2022.
//
#include "Player.h"
#include "utilities.h"
#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

class Wizard : public Player{
public:
    Wizard (const std::string &name, const std::string &type) :
            Player(name, type){}
    Wizard(const Wizard& wizard) = default;
    Wizard& operator=(const Wizard& wizard) = default;
    ~Wizard() override = default;
    void heal(int HPToAdd) override;
    void addCoins(int coinsToAdd) override;
    int getAttackStrength() const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_WIZARD_H
