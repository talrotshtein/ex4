//
// Created by Tal on 6/10/2022.
//
#include "Rogue.h"

static const int MAX_HP = 100;


void Rogue::heal(int HPToAdd) {
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


void Rogue::addCoins(int coinsToAdd) {
    if(coinsToAdd>0){
        this->m_coins += 2*coinsToAdd;
    }
}

int Rogue::getAttackStrength() const {
    return m_level + m_force;
}

