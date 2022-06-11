//
// Created by shahar on 10/06/2022.
//

#include "Merchant.h"
static const int HEAL_POINTS_PRICE = 5;
static const int FORCE_POINTS_PRICE = 10;

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getNumberOfCoins());
    char input[1];
    std::cin.getline(input, 1);
    while (input[0] != '0' && input[0] != '1' && input[0] != '2') {
        printInvalidInput();
        std::cin.getline(input, 1);
    }
    if(input[0] == '0')
    {
        printMerchantSummary(std::cout, player.getPlayerName(), 0, 0);
    }
    if(input[0] == '1')
    {
        printMerchantSummary(std::cout, player.getPlayerName(), 1, HEAL_POINTS_PRICE);
        player.heal(1);
    }
    if(input[0] == '2')
    {
        printMerchantSummary(std::cout, player.getPlayerName(), 2, FORCE_POINTS_PRICE);
        player.buff(1);
    }
}

std::ostream &Merchant::operator<<(std::ostream &os) {
    printCardDetails(os, "Merchant");
    printEndOfCardDetails(os);
}

