//
// Created by talro on 20/06/2022.
//

static const int FIGHTER_DIFF = 2;

#include "Gang.h"

void Gang::addMonster(std::string monsterName) {
    if(monsterName == "Dragon")
    {
        m_gang.push_back(std::unique_ptr<Card>(new Dragon()));
        return;
    }
    if(monsterName == "Goblin")
    {
        m_gang.push_back(std::unique_ptr<Card>(new Goblin()));
        return;
    }
    if(monsterName == "Vampire")
    {
        m_gang.push_back(std::unique_ptr<Card>(new Vampire()));
        return;
    }
}

void Gang::applyEncounter(Player &player) const {
    bool hasLost = false;
    int startingHp = player.getCurrentHp();
    for (int i = 0; (unsigned)i < m_gang.size(); ++i)
    {
        m_gang[i]->applyInGangEncounter(player, hasLost);
        if(startingHp > player.getCurrentHp() && !hasLost){
            hasLost = true;
        }
    }
    if(!hasLost){
        printWinBattle(player.getPlayerName(), "Gang");
        player.levelUp();
    }
}

std::ostream &Gang::print(std::ostream &os) const {
    printCardDetails(os, "Gang");
    printEndOfCardDetails(os);
    return os;
}