//
// Created by Tal on 6/11/2022.
//
#include "Mtmchkin.h"

static const int MINIMUM_DECK_SIZE = 5;
static const int MINIMUM_PLYAER_AMOUNT = 2;
static const int MAXIMUM_PLYAER_AMOUNT = 6;

Mtmchkin::Mtmchkin(const std::string fileName) {
    std::ifstream source(fileName);
    if(!source)
    {
        //add throw - DeckFileNotFound
    }
    char line[256];
    std::string stringLine;
    while (source.getline(line, sizeof(line)))
    {
        stringLine = Mtmchkin::convertToString(line,sizeof(line));
        //add try
        checkAndPushCardType(stringLine);
    }
    if(m_deck.size() < MINIMUM_DECK_SIZE)
    {
        //throw
    }
    printStartGameMessage();
    printEnterTeamSizeMessage();
    std::string input;
    std::cin >> input;
    while (std::stoi(input) > MAXIMUM_PLYAER_AMOUNT && std::stoi(input) < MINIMUM_PLYAER_AMOUNT)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> input;
    }

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

static std::string convertToString(char* a, int size)
{
    int i;
    std::string str = "";
    for (i = 0; i < size; i++) {
        str = str + a[i];
    }
    return str;
}

