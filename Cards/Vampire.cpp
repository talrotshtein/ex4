//
// Created by Tal on 6/11/2022.
//

#include "Vampire.h"

static const int FORCE = 10;
static const int LOOT = 2;
static const int DAMAGE = 10;
static const int NERF_UPON_LOSS = 1;

void Vampire::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= FORCE)
    {
        printWinBattle(player.getPlayerName(), "Vampire");
        player.levelUp();
        player.addCoins(LOOT);
    }
    else
    {
        printLossBattle(player.getPlayerName(), "Vampire");
        player.damage(DAMAGE);
        player.nerf(NERF_UPON_LOSS);
    }
}

void Vampire::applyInGangEncounter(Player &player, bool punishOnly) const {
    if(punishOnly || player.getAttackStrength() < FORCE){
        printLossBattle(player.getPlayerName(), "Vampire");
        player.damage(DAMAGE);
        player.nerf(NERF_UPON_LOSS);
    }
    else{
        player.addCoins(LOOT);
    }
}

std::ostream &Vampire::print(std::ostream &os) const {
    printCardDetails(os, "Vampire");
    printMonsterDetails(os, FORCE, DAMAGE, LOOT, false);
    printEndOfCardDetails(os);
    return os;
}

