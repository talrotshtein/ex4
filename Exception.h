//
// Created by Tal on 6/11/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class DeckFileNotFound : public std::exception{
public:
    const char * what() const noexcept override{
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception{
public:
    DeckFileFormatError(int index)
    {
        this->m_index = index;
    }

    const char * what() const noexcept override
    {
        std::string message = "Deck File Error: File format error in line " + std::to_string(m_index)+"\0";
        char* tempString = new char[message.size()];
        std::strcpy(tempString, message.c_str());
        return tempString;
    }

private:
    int m_index;
};

class DeckFileInvalidSize : public std::exception{
public:
    const char * what() const noexcept override{
        return  "Deck File Error: Deck size is invalid";
    }
};


#endif //EX4_EXCEPTION_H
