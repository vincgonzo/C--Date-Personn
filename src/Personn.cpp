#include <string>
#include <vector>
#include <ctime>
#include "Personn.h"

using namespace std;

Personn::Personn(){};

Personn::Personn(string fname, string lname, unsigned int day, unsigned int month, unsigned int year):
m_firstName(fname),
m_LastName(lname),
m_dateOfBirth(day, month, year)
{
}


string Personn::toString() const
{
    return "my name is " + m_firstName + " " + m_LastName;
}
