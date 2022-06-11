//
// Created by shahar on 10/06/2022.
//
#include "Card.h"
#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H


class Merchant : public Card{
public:
    Merchant() : Card("Merchant"){}
    void applyEncounter(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_MERCHANT_H
