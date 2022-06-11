//
// Created by Tal on 6/11/2022.
//
#include "Mtmchkin.h"

static const int MINIMUM_DECK_SIZE = 5;
static const int MINIMUM_PLAYER_AMOUNT = 2;
static const int MAXIMUM_PLAYER_AMOUNT = 6;

Mtmchkin::Mtmchkin(const std::string fileName) {
    std::ifstream source(fileName);
    if(!source)
    {
        //add throw - DeckFileNotFound
    }
    std::string line;
    int index  = 0;
    while (std::getline(source, line))
    {
        //add try
        checkAndPushCardType(line);
        index++;
    }
    if(m_deck.size() < MINIMUM_DECK_SIZE) {
        //throw
    }
    int numOfPlayers = receiveNumOfPlayersInput();
    for (int i = 0; i < numOfPlayers; ++i) {
        addNewPlayer();
    }
}

void Mtmchkin::addNewPlayer() {
    std::string inputName;
    std::string inputClass;
    bool validName = false, validClass = false;
    while (!validName && !validClass)
    {
        printInsertPlayerMessage();
        std::cin >> inputName;
        std::cin >> inputClass;
        if(isNameValid(inputName)){
            validName = true;
        }
        else{
            printInvalidName();
            continue;
        }
        if(isClassValid(inputClass)){
            validClass = true;
        }
        else{
            printInvalidClass();
            continue;
        }
    }
    pushNewPlayer(inputName, inputClass);
}

void Mtmchkin::pushNewPlayer(std::string& name, std::string& player_class) {
    if(name == "Rogue")
    {
        m_players.push(*(std::unique_ptr<Rogue>(new Rogue(name, player_class))));
    }
    else if(name == "Wizard")
    {
        m_players.push(*(std::unique_ptr<Wizard>(new Wizard(name, player_class))));
    }
    else{
        m_players.push(*(std::unique_ptr<Fighter>(new Fighter(name, player_class))));
    }
}

bool Mtmchkin::isNameValid(std::string &name) {
    if(name.size() > 15){
        return false;
    }
    std::string::iterator iterator;
    for (iterator = name.begin(); iterator < name.end(); iterator++) {
        if(*iterator > 'z' || *iterator < 'a'){
            return false;
        }
    }
    return true;
}

bool Mtmchkin::isClassValid(std::string &player_class) {
    if(player_class != "Fighter" && player_class!="Wizard" && player_class != "Rogue"){
        return false;
    }
    return true;
}



int Mtmchkin::receiveNumOfPlayersInput()
{
    std::string input;
    int numOfPlayers;
    bool validInput = false;
    while (!validInput)
    {
        try{
            printEnterTeamSizeMessage();
            std::cin >> input;
            numOfPlayers = stoi(input);
            if(numOfPlayers > MAXIMUM_PLAYER_AMOUNT || numOfPlayers < MINIMUM_PLAYER_AMOUNT){
                validInput = true;
            }
        }
        catch(std::exception &e){
            printInvalidTeamSize();
            continue;
        }
    }
    return numOfPlayers;
}

void Mtmchkin::checkAndPushCardType(std::string& line){
    if(line == "Barfight"){
        m_deck.push(*(std::unique_ptr<Card>(new Barfight())));
        return;
    }
    if(line == "Dragon"){
        m_deck.push(*(std::unique_ptr<Card>(new Dragon())));
        return;
    }
    if(line == "Fairy"){
        m_deck.push(*(std::unique_ptr<Card>(new Fairy())));
        return;
    }
    if(line == "Goblin"){
        m_deck.push(*(std::unique_ptr<Card>(new Goblin())));
        return;
    }
    if(line == "Merchant"){
        m_deck.push(*(std::unique_ptr<Card>(new Merchant())));
        return;
    }
    if(line == "Pitfall"){
        m_deck.push(*(std::unique_ptr<Card>(new Pitfall())));
        return;
    }
    if(line == "Treasure"){
        m_deck.push(*(std::unique_ptr<Card>(new Treasure())));
        return;
    }
    if(line == "Vampire"){
        m_deck.push(*(std::unique_ptr<Card>(new Vampire())));
        return;
    }
    //throw DeckFileFormatError;
}


