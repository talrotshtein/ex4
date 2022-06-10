//
// Created by Tal on 6/10/2022.
//
#include <string>
#include "utilities.h"
#include "Players/Player.h"
#ifndef EX4_CARD_H
#define EX4_CARD_H

class Card{
protected:
    std::string m_name;
public:
    Card(const std::string &name);
    virtual void applyEncounter(Player& player) const = 0;
    virtual std::ostream& operator<<(std::ostream& os) = 0;
};

#endif //EX4_CARD_H
