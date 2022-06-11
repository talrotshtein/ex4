//
// Created by Tal on 6/10/2022.
//

#include "Fighter.h"

static const int MAX_HP = 100;


void Fighter::heal(int HPToAdd) {
    if(HPToAdd <= 0){
        return;
    }
    if(this->m_HP + HPToAdd >= MAX_HP)
    {
        this->m_HP = MAX_HP;
    }
    else
    {
        this->m_HP += HPToAdd;
    }
}

void Fighter::addCoins(int coinsToAdd) {
    if(coinsToAdd>0){
        this->m_coins += coinsToAdd;
    }
}

int Fighter::getAttackStrength() const {
    return m_level + m_force*2;
}

std::ostream &Fighter::print(std::ostream &os) const {
    printPlayerDetails(os, m_name, "Fighter", m_level, m_force, m_HP, m_coins);
    return os;
}
