//
// Created by Tal on 6/10/2022.
//
#include "Wizard.h"

static const int MAX_HP = 100;

void Wizard::heal(int HPToAdd) {
    if(HPToAdd <= 0){
        return;
    }
    if(this->m_HP + 2*HPToAdd >= MAX_HP)
    {
        this->m_HP = MAX_HP;
    }
    else
    {
        this->m_HP += 2*HPToAdd;
    }
}

void Wizard::addCoins(int coinsToAdd) {
    if(coinsToAdd>0){
        this->m_coins += coinsToAdd;
    }
}

int Wizard::getAttackStrength() const {
    return m_level + m_force;
}

std::ostream &Wizard::operator<<(std::ostream& os) {
    printPlayerDetails(os, m_name, "Wizard", m_level, m_force, m_HP, m_coins);
}
