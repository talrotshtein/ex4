//
// Created by Tal on 6/10/2022.
//
#include "Pitfall.h"

static const int HP_TO_REMOVE = 10;

void Pitfall::applyEncounter(Player &player) const {
    bool isRogue = true;
    if(player.getType() != "Rogue")
    {
        isRogue = false;
        player.damage(HP_TO_REMOVE);
    }
    printPitfallMessage(isRogue);
}

std::ostream &Pitfall::print(std::ostream &os) const {
    printCardDetails(os, "Pitfall");
    printEndOfCardDetails(os);
}

/*
std::ostream &Pitfall::operator<<(std::ostream &os) {
    printCardDetails(os, "Pitfall");
    printEndOfCardDetails(os);
}*/
