//
// Created by Tal on 6/11/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class DeckFileNotFound : public std::exception{
public:
    const char * what()
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception{
public:
    DeckFileFormatError(int index)
    {
        this->m_index = index;
    }

    const char * what()
    {
        char message[64] = "Deck File Error: File format error in line";
        char index[32];
        sprintf(index, "%d", m_index);
        strcat(message, index);
        return message;
    }

private:
    int m_index;
};

class DeckFileInvalidSize : public std::exception{
public:
    const char * what()
    {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif //EX4_EXCEPTION_H
