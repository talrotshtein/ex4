//
// Created by shahar on 10/06/2022.
//

#include "Barfight.h"

static const int HP_TO_REMOVE = 10;

void Barfight::applyEncounter(Player &player) const {
    bool isFighter = true;
    if(player.getType() != "Fighter")
    {
        isFighter = false;
        player.damage(HP_TO_REMOVE);
    }
    printBarfightMessage(isFighter);
}

std::ostream &Barfight::print(std::ostream &os) const {
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
    return os;
}
