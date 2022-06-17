//
// Created by Tal on 6/17/2022.
//
#include "Mtmchkin.h"


int main(){
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try{
        Mtmchkin game("inputs/deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch(std::exception &e){
        std::cout << e.what();
        return 1;
    }
    return 0;
}
