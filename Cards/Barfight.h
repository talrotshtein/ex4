//
// Created by shahar on 10/06/2022.
//
#include "Card.h"
#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

class Barfight : public Card{
public:
    Barfight() : Card("Pitfall"){}
    void applyEncounter(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
};
#endif //EX4_BARFIGHT_H
