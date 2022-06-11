//
// Created by Tal on 6/10/2022.
//

#include "Card.h"
#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

class Pitfall : public Card{
public:
    Pitfall() : Card("Pitfall"){}
    void applyEncounter(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_PITFALL_H
