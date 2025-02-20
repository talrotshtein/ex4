//
// Created by Tal on 6/11/2022.
//

#include "Dragon.h"

static const int FORCE = 25;
static const int LOOT = 1000;

void Dragon::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= FORCE)
    {
        printWinBattle(player.getPlayerName(), "Dragon");
        player.levelUp();
        player.addCoins(LOOT);
    }
    else
    {
        printLossBattle(player.getPlayerName(), "Dragon");
        player.damage(player.getCurrentHp());
    }
}

void Dragon::applyInGangEncounter(Player &player, bool punishOnly) const {
    if(punishOnly || player.getAttackStrength() < FORCE){
        printLossBattle(player.getPlayerName(), "Dragon");
        player.damage(player.getCurrentHp());
    }
    else{
        player.addCoins(LOOT);
    }
}

std::ostream &Dragon::print(std::ostream &os) const {
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, FORCE, 0, LOOT, true);
    printEndOfCardDetails(os);
    return os;
}
