#ifndef PERSONN_H_INCLUDED
#define PERSONN_H_INCLUDED

#include <iostream>
#include "Date.h"

class Personn {

    public:
        Personn();
        Personn(std::string m_firstName, std::string m_lastName, unsigned int day, unsigned int month, unsigned int year);
        std::string toString() const;

    private:
        std::string m_firstName, m_LastName;
        Date m_dateOfBirth;
};

#endif // PERSONN_H_INCLUDED
