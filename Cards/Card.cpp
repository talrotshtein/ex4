//
// Created by Tal on 6/10/2022.
//
#include "Card.h"

Card::Card(const std::string &name) {
    m_name = name;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    return card.print(os);
}
