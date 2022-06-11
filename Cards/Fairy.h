//
// Created by shahar on 10/06/2022.
//
#include "Card.h"
#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

class Fairy : public Card{
public:
    Fairy() : Card("Pitfall"){}
    void applyEncounter(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_FAIRY_H
