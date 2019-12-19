#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "Date.h"

template <typename T>
string to_string(T val) {
  ostringstream oss;
  oss << val;
  return oss.str();
}

Date::Date() {
  time_t rawtime;
  struct tm * timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  day = timeinfo->tm_mday;
  month = 1 + timeinfo->tm_mon;
  year = 1900 + timeinfo->tm_year;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
  if(!validDate(d, m, y)) throw DateInvalide();
}

int Date::getDay()   const { return day;   }
int Date::getMonth() const { return month; }
int Date::getYear()  const { return year;  }

void Date::setDay(int aDay) {
  if(!validDate(aDay, month, year))
    throw DateInvalide();
  day = aDay;
}

void Date::setMonth(int aMonth) {
  if(!validDate(day, aMonth, year))
    throw DateInvalide();
  month = aMonth;
}

void Date::setYear(int aYear) {
  if(!validDate(day, month, aYear))
    throw DateInvalide();
  year = aYear;
}

string Date::toString() const {
  return DAYS_IN_FRENCH[dayOfWeek()] + " " +
         to_string(day) + " " +
         MONTHS_IN_FRENCH[month - 1] + " " +
         to_string(year) +
         " le jour num " + to_string(dayOfYear()) + " de l'annee";
}

Date & Date::operator++() {
  if(!lastDayOfMonth())
    ++day;
  else {
    day = 1;
    if(month != 12)
      ++month;
    else {
      month = 1;
      ++year;
    }
  }
  return *this;
}

Date Date::operator++(int) {
  Date tmp = *this;
  ++*this;
  return tmp;
}

bool Date::lastDayOfMonth() const {
  return day == daysInMonth(month, year);
}

int Date::dayOfYear() const {
  int dayOfYear = day;
  for (int i = 1; i < month; i++)
    dayOfYear += daysInMonth(i, year);
  return dayOfYear;
}

/**
 * @returns 0=monday, 1=tuesday, ..., 6=sunday see
 * http://en.wikipedia.org/wiki/Zeller's_congruence
 */
int Date::dayOfWeek() const {
    int m = month;     // local copies because
    int y = year;      // month and year should not be modified
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }

    int century = y / 100;
    int yearOfCentury = y % 100;
    int dayOfWeek = (day
            + (((m + 1) * 26) / 10)
            + yearOfCentury
            + (yearOfCentury / 4)
            + (century / 4)
            + 5 * century) % 7;

    return (dayOfWeek + 5) % 7;
}

int Date::daysInMonth(int aMonth, int aYear) {
  return DAYS_IN_MONTHS[aMonth - 1] + (isLeapYear(aYear) && aMonth == 2 ? 1 : 0);
}

bool Date::isLeapYear(int aYear) {
  return aYear % 400 == 0 || (aYear % 100 != 0 && aYear % 4 == 0);
}

ostream & operator<<(ostream & fout, const Date & d) {
  fout << d.toString();
  return fout;
}

istream & operator>>(istream & fin, Date & date) {
  int d, m, y;
  bool saisieInvalide = true;
  do {
    try {
      cin >> d >> m >> y;
      Date saisie(d, m, y);
      saisieInvalide = false;
      date = saisie;
    }
    catch(...) {
      cin.clear();           // réinitialise l'état de cin
      cin.ignore(256, '\n'); // supprime les caractères restants
      cout << "Date invalide!\nRecommencez...\n";
    }
  } while(saisieInvalide);
  return fin;
}


bool operator==(const Date & d1, const Date & d2) {
  return d1.getDay()   == d2.getDay()   &&
         d1.getMonth() == d2.getMonth() &&
         d1.getYear()  == d2.getYear();
}

bool operator!=(const Date & d1, const Date & d2) {
  return !(d1 == d2);
}

static int toUSInteger(int day, int month, int year) {
  return 10000 * year + 100 * month + day;
}

bool operator< (const Date & d1, const Date & d2) {
  return toUSInteger(d1.getDay(), d1.getMonth(), d1.getYear()) <
         toUSInteger(d2.getDay(), d2.getMonth(), d2.getYear());
}

bool operator<=(const Date & d1, const Date & d2) { return d1 < d2 || d1 == d2; }
bool operator> (const Date & d1, const Date & d2) { return !(d1 <= d2); }
bool operator>=(const Date & d1, const Date & d2) { return ! (d1 < d2); }


const std::vector<char> Date::DAYS_IN_MONTHS = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::vector<string> Date::MONTHS_IN_FRENCH = {
        "Janvier", "Fevrier", "Mars",
        "Avril", "Mai", "Juin", "Juillet", "Aout",
        "Septembre", "Octobre", "Novembre", "Decembre"
    };
const vector<string> Date::DAYS_IN_FRENCH = {
        "Lundi", "Mardi", "Mercredi",
        "Jeudi", "Vendredi", "Samedi",
        "Dimanche"
    };

