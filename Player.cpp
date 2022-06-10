//
// Created by Tal on 6/10/2022.
//

#include "Player.h"
#include "utilities.h"

static const int MAX_LEVEL = 10;
static const int MAX_HP = 100;
static const int DEFAULT_FORCE = 5;
static const int DEFAULT_COINS = 10;

Player::Player(const std::string name, int HP, int force)
{
    this->m_name = name;
    if(HP > 0){
        this->m_HP = HP;
    }
    else if(HP<=0)
    {
        this->m_HP = MAX_HP;
    }
    if(force >0){
        this->m_force = force;
    }
    else if(force<=0)
    {
        this->m_force = DEFAULT_FORCE;
    }
    this->m_coins = DEFAULT_COINS;
    this->m_level = 1;
}

void Player::levelUp()
{
    if (this->m_level<MAX_LEVEL)
    {
        this->m_level++;
    }
}

int Player::getLevel() const
{
    return this->m_level;
}

bool Player::pay(int coinsToPay) {
    if(coinsToPay <= 0){
        return true;
    }
    if(coinsToPay > m_coins){
        return false;
    }
    else{
        m_coins-=coinsToPay;
        return true;
    }
}

bool Player::isKnockedOut() const{
    if(m_HP == 0){
        return true;
    }
    return false;
}

