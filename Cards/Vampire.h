//
// Created by Tal on 6/11/2022.
//
#include "Card.h"
#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

class Vampire : public Card{
public:
    Vampire() : Card("Vampire"){}
    void applyEncounter(Player& player) const override;
    void applyInGangEncounter(Player& player, bool punishOnly) const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_VAMPIRE_H
