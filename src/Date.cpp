#include "Date.h"

using namespace std;

Date::Date(int m_day, int m_month, int m_year): m_day(m_day), m_month(m_month), m_year(m_year)
{

}

void Date::increment()
{
    if(m_day+1 < dayInMonth())
    {
        m_day++;
    }else if(m_month+1 < 13)
    {
        m_day = 1;
        m_month++;
    }
    else
    {
        m_day = 1;
        m_month = 1;
        m_year++;
    }
}

void Date::prettyPrint()
{
    cout << m_day << '/' << m_month << '/' << m_year << endl;
}

int Date::dayInMonth()
{
    int nbr(0);
    switch(m_month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        nbr = 31;
        break;
    case 2:
        nbr = (isBisextile())? 29 : 28;
        break;
    default:
        nbr = 30;
        break;
    }
    return nbr;
}

int Date::dayOfYear()
{
    return m_day;
}
void Date::setMonth(unsigned int m)
{
    if(m > 0 && m < 12)
        m_month = m;
}

void Date::setDay(unsigned int d)
{
    if(d > 0 && d < dayInMonth())
        m_day = d;
}

void Date::setYear(unsigned int y)
{
    if(y > 2019)
        m_year = y;
}
bool Date::isBisextile()
{
    return ((m_year%4==0&&m_year%100 !=0) || m_year%400==0);
}

string Date::getCurrentMonth()
{
    return m_month_name[m_month-1];
}

string Date::toString()
{
    return std::to_string(m_day) + " " + getCurrentMonth() + " " + std::to_string(m_year);
}
