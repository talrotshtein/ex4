#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <queue>
#include <fstream>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Exception.h"

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    int m_round;
    int m_deadPlayers;
    int m_playersWon;
    std::queue<std::unique_ptr<Card>> m_deck;
    std::vector<std::unique_ptr<Player>> m_players;
    void checkAndPushCardType(std::string& line, int index);
    static int receiveNumOfPlayersInput();
    void addNewPlayer();
    static bool isNameValid(std::string& name);
    static bool isClassValid(std::string& player_class);
    void pushNewPlayer(std::string& name, std::string& player_class);
    void moveDeadPlayerBack(int index);
    void moveWinnerForward(int index);
};



#endif /* MTMCHKIN_H_ */
