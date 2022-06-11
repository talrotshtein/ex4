//
// Created by shahar on 10/06/2022.
//
#include "Fairy.h"

static const int HP_TO_ADD = 10;

void Fairy::applyEncounter(Player &player) const {
    bool isWizard = false;
    if(player.getType() == "Wizard")
    {
        isWizard = true;
        player.heal(HP_TO_ADD);
    }
    printFairyMessage(isWizard);
}

std::ostream &Fairy::print(std::ostream &os) const {
    printCardDetails(os, "Fairy");
    printEndOfCardDetails(os);
    return os;
}

