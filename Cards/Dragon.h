//
// Created by Tal on 6/11/2022.
//
#include "Card.h"
#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

class Dragon : public Card{
public:
    Dragon() : Card("Dragon"){}
    void applyEncounter(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_DRAGON_H
