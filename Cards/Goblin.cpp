//
// Created by Tal on 6/11/2022.
//

#include "Goblin.h"

static const int FORCE = 6;
static const int LOOT = 2;
static const int DAMAGE = 10;

void Goblin::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= FORCE)
    {
        printWinBattle(player.getPlayerName(), "Goblin");
        player.levelUp();
        player.addCoins(LOOT);
    }
    else
    {
        printLossBattle(player.getPlayerName(), "Goblin");
        player.damage(DAMAGE);
    }
}

std::ostream &Goblin::print(std::ostream &os) const {
    printCardDetails(os, "Goblin");
    printMonsterDetails(os, FORCE, DAMAGE, LOOT, false);
    printEndOfCardDetails(os);
    return os;
}
