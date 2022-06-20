//
// Created by Tal on 6/11/2022.
//
#include "Card.h"
#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

class Goblin : public Card{
public:
    Goblin() : Card("Goblin"){}
    void applyEncounter(Player& player) const override;
    void applyInGangEncounter(Player& player, bool punishOnly) const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_GOBLIN_H
