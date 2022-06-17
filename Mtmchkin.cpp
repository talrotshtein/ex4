//
// Created by Tal on 6/11/2022.
//
#include "Mtmchkin.h"

static const int MINIMUM_DECK_SIZE = 5;
static const int MINIMUM_PLAYER_AMOUNT = 2;
static const int MAXIMUM_PLAYER_AMOUNT = 6;
static const int MAXIMUM_PLAYER_LEVEL = 10;

Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();
    m_round = 0;
    m_deadPlayers = 0;
    m_playersWon = 0;
    std::ifstream source(fileName);
    if(!source.is_open()){
        throw DeckFileNotFound();
    }
    std::string line;
    int index  = 1;
    while (std::getline(source, line))
    {
        checkAndPushCardType(line, index);
        index++;
    }
    if(m_deck.size() < MINIMUM_DECK_SIZE) {
        throw DeckFileInvalidSize();
    }
    int playersInGame = receiveNumOfPlayersInput();
    for (int i = 0; i < playersInGame; ++i) {
        addNewPlayer();
    }
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(++m_round);
    for (int i = 0; i < m_players.size(); ++i)
    {
        if(!m_players[i]->isKnockedOut() && m_players[i]->getLevel() < MAXIMUM_PLAYER_LEVEL)
        {
            printTurnStartMessage(m_players[i]->getPlayerName());
            m_deck.front()->applyEncounter(*m_players[i]);
            if (m_players[i]->isKnockedOut()){
                moveDeadPlayerBack( i);
                i--;
                m_deadPlayers++;
            }
            else if(m_players[i]->getLevel() == MAXIMUM_PLAYER_LEVEL){
                moveWinnerForward(i);
                m_playersWon++;
            }
            std::unique_ptr<Card> temp = std::move(this->m_deck.front());
            m_deck.pop();
            this->m_deck.push(std::move(temp));
        }
    }
    if(isGameOver()){
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    for (int i = 0; i < m_players.size(); ++i)
    {
        printPlayerLeaderBoard(i+1, *m_players[i]);
    }
}

void Mtmchkin::moveDeadPlayerBack(int index)
{
    int iterations = m_players.size() - 1 - m_deadPlayers;
    for (int i = index; i < iterations; ++i)
    {
            std::swap(m_players[index], m_players[index + 1]);
    }
}

void Mtmchkin::moveWinnerForward(int index)
{
    int iterations = index - m_playersWon;
    for (int i = index; i < iterations; ++i)
    {
        std::swap(m_players[index], m_players[index - 1]);
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_round;
}

bool Mtmchkin::isGameOver() const {
    return m_playersWon + m_deadPlayers == m_players.size();
}

void Mtmchkin::addNewPlayer() {
    std::string inputName;
    std::string inputClass;
    bool validName = false, validClass = false;
    printInsertPlayerMessage();
    while (!validName || !validClass)
    {
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
    if(player_class == "Rogue")
    {
        m_players.push_back(std::unique_ptr<Rogue>(new Rogue(name, player_class)));
    }
    else if(player_class == "Wizard")
    {
        m_players.push_back(std::unique_ptr<Wizard>(new Wizard(name, player_class)));
    }
    else{
        m_players.push_back(std::unique_ptr<Fighter>(new Fighter(name, player_class)));
    }
}

bool Mtmchkin::isNameValid(std::string &name) {
    if(name.size() > 15){
        return false;
    }
    std::string::iterator iterator;
    for (iterator = name.begin(); iterator < name.end(); iterator++) {
        if(!((*iterator <= 'z' && *iterator >= 'a') || (*iterator <= 'Z' && *iterator >= 'A'))){
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
            if(numOfPlayers <= MAXIMUM_PLAYER_AMOUNT && numOfPlayers >= MINIMUM_PLAYER_AMOUNT){
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

void Mtmchkin::checkAndPushCardType(std::string& line, int index)
{
    if(line == "Barfight"){
        m_deck.push(std::unique_ptr<Card>(new Barfight()));
        return;
    }
    if(line == "Dragon"){
        m_deck.push(std::unique_ptr<Card>(new Dragon()));
        return;
    }
    if(line == "Fairy"){
        m_deck.push(std::unique_ptr<Card>(new Fairy()));
        return;
    }
    if(line == "Goblin"){
        m_deck.push(std::unique_ptr<Card>(new Goblin()));
        return;
    }
    if(line == "Merchant"){
        m_deck.push(std::unique_ptr<Card>(new Merchant()));
        return;
    }
    if(line == "Pitfall"){
        m_deck.push(std::unique_ptr<Card>(new Pitfall()));
        return;
    }
    if(line == "Treasure"){
        m_deck.push(std::unique_ptr<Card>(new Treasure()));
        return;
    }
    if(line == "Vampire"){
        m_deck.push(std::unique_ptr<Card>(new Vampire()));
        return;
    }
    throw DeckFileFormatError(index);
}


