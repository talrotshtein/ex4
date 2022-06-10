//
// Created by Tal on 6/10/2022.
//
#include "Card.h"
#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

class Treasure : public Card{
public:
    Treasure();
    void applyEncounter(Player& player) const override;
    std::ostream& operator<<(std::ostream& os) override;
};

#endif //EX4_TREASURE_H
