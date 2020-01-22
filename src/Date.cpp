#include <string>
#include <vector>
#include <ctime>
#include "Date.h"

using namespace std;

Date::Date(){
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int day   = timeinfo->tm_mday;
    int month = 1 + timeinfo->tm_mon;
    int year  = 1900 + timeinfo->tm_year;
}

Date::Date(int d = 0, int m = 0, int y = 0): m_day(d), m_month(m), m_year(y) {
  if(!validDate(d, m, y)) throw DateInvalide();
}

void Date::increment()
{
    if(m_day+1 < dayInMonth(m_month, m_year))
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

int Date::dayInMonth(unsigned int month, unsigned int year)
{
    int nbr(0);
    switch(month){
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
        nbr = (isBisextile(year))? 29 : 28;
        break;
    default:
        nbr = 30;
        break;
    }
    return nbr;
}

int Date::dayOfYear() const
{
    return m_day;
}
void Date::setMonth(unsigned int m)
{
    m_month = (m > 0 && m <= 12) ? m : throw;
}

void Date::setDay(unsigned int d)
{
    if(d > 0 && d < dayInMonth(d, m_year))
        m_day = d;
}

void Date::setYear(unsigned int y)
{
    if(y > 1900)
        m_year = y;
}
bool Date::isBisextile(unsigned int year)
{
    return ((year%4 == 0 && year%100 != 0) || year%400 == 0);
}

bool Date::validDate(unsigned int day, unsigned int month, unsigned int year) {
      return day >= 1  && day <= dayInMonth(month, year) && month >= 1 && month <= 12;
}

string Date::getCurrentMonth()
{
    return m_month_name[m_month-1];
}

string Date::toString()
{
    return std::to_string(m_day) + " " + getCurrentMonth() + " " + std::to_string(m_year);
}
