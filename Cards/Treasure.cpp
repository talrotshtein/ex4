//
// Created by Tal on 6/10/2022.
//
#include "Treasure.h"

static const int COINS_TO_ADD = 10;

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(COINS_TO_ADD);
    printTreasureMessage();
}

std::ostream &Treasure::print(std::ostream &os) const {
    printCardDetails(os, "Treasure");
    printEndOfCardDetails(os);
    return os;
}
