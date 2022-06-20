//
// Created by talro on 20/06/2022.
//

#include <vector>
#include "Card.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Vampire.h"
#include <memory>
#include <fstream>
#ifndef EX4_GANG_H
#define EX4_GANG_H

class Gang: public Card{
public:
    Gang() : Card("Gang"){}
    void applyEncounter(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
    void addMonster(std::string monsterName);

private:
    std::vector<std::unique_ptr<Card>> m_gang;
};

#endif //EX4_GANG_H
