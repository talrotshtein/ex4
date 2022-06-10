//
// Created by Tal on 6/10/2022.
//

#include "Player.h"
#include "utilities.h"
#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

class Wizard : public Player{
    Wizard (const std::string &name, int HP=100, int force=5) :
            Player(name, HP, force){}
    Wizard(const Wizard& wizard) = default;
    Wizard& operator=(const Wizard& wizard) = default;
    ~Wizard() override = default;
    std::ostream& operator<<(std::ostream& os) override;
    void heal(int HPToAdd) override;
    void addCoins(int coinsToAdd) override;
    int getAttackStrength() const override;
};

#endif //EX4_WIZARD_H
