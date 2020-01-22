#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

struct DateInvalide {
    DateInvalide() {
        std::cout << "Erreur";
    }
};

class Date {

    public:
        Date();
        Date(int m_day, int m_month, int m_year);
        void prettyPrint();
        void increment();
        int dayOfYear() const;
        int dayInMonth(unsigned int m, unsigned int y );
        void setMonth(unsigned int m);
        void setDay(unsigned int d);
        void setYear(unsigned int y);
        bool isBisextile(unsigned int y);
        bool validDate(unsigned int day, unsigned int month, unsigned int year);

        std::string toString();
        std::string getCurrentMonth();

    private:
        int m_day, m_month, m_year;
        std::vector <std::string> m_month_name = {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};
};

#endif // DATE_H_INCLUDED
