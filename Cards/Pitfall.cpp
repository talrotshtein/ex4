//
// Created by Tal on 6/10/2022.
//
#include "Pitfall.h"

static const int COINS_TO_ADD = 10;
static const int HP_TO_REMOVE = 10;

Pitfall::Pitfall() {
    this->m_name = "Pitfall";
}

void Pitfall::applyEncounter(Player &player) const {
    bool isRogue = true;
    if(player.getType() != "Rogue")
    {
        isRogue = false;
        player.damage(HP_TO_REMOVE);
    }
    printPitfallMessage(isRogue);
}

std::ostream &Pitfall::operator<<(std::ostream &os) {
    printCardDetails(os, "Pitfall");
}
