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
        this->m_message = "Deck File Error: File format error in line";
    }

    const char * what() const noexcept override
    {

        char index[32];
        sprintf(index, "%d", m_index);
        strcat(m_message, index);
        return m_message;
    }

private:
    int m_index;
    char * m_message;
};

class DeckFileInvalidSize : public std::exception{
public:
    const char * what() const noexcept override{
        return  "Deck File Error: Deck size is invalid";
    }
};


#endif //EX4_EXCEPTION_H
