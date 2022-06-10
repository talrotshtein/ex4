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
    std::ostream& operator<<(std::ostream& os) override;
};
#endif //EX4_BARFIGHT_H
