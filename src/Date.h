#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

class Date {

    public:
        Date(int m_day, int m_month, int m_year);
        void prettyPrint();
        void increment();
        int dayOfYear();
        int dayInMonth();
        void setMonth(unsigned int m);
        void setDay(unsigned int d);
        void setYear(unsigned int y);
        bool isBisextile();

        std::string toString();
        std::string getCurrentMonth();

    private:
        int m_day, m_month, m_year;
        std::vector <std::string> m_month_name = {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};

};

#endif // DATE_H_INCLUDED
