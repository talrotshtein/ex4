//
// Created by shahar on 10/06/2022.
//

#include "Merchant.h"
static const int HEAL_POINTS_PRICE = 5;
static const int FORCE_POINTS_PRICE = 10;

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getNumberOfCoins());
    char input[1];
    std::cin >> input;
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
        if(player.getNumberOfCoins() >= HEAL_POINTS_PRICE){
            printMerchantSummary(std::cout, player.getPlayerName(), 1, HEAL_POINTS_PRICE);
            player.pay(HEAL_POINTS_PRICE);
            player.heal(1);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), 0, 0);
        }
    }
    if(input[0] == '2')
    {
        if(player.getNumberOfCoins() >= FORCE_POINTS_PRICE) {
            printMerchantSummary(std::cout, player.getPlayerName(), 2, FORCE_POINTS_PRICE);
            player.pay(FORCE_POINTS_PRICE);
            player.buff(1);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), 0, 0);
        }
    }
}

std::ostream &Merchant::print(std::ostream &os) const {
    printCardDetails(os, "Merchant");
    printEndOfCardDetails(os);
    return os;
}

