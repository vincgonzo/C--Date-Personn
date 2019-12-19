#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

class DateInvalide {};

class Date {
public:
  Date();
  Date(int d, int m, int y);
  Date(const Date & date) = default;
  Date & operator=(const Date & date) = default;

  int getDay() const;
  int getMonth() const;
  int getYear() const;

  void setDay(int aDay);
  void setMonth(int aMonth);
  void setYear(int aYear);

  std::string toString() const;

  Date & operator++();
  Date operator++(int);

  bool lastDayOfMonth() const;

  int dayOfYear() const;

  int dayOfWeek() const;

  static int daysInMonth(int aMonth, int aYear);

  static bool isLeapYear(int aYear);

//  friend std::istream & operator>>(std::istream & fin, Date & date);

private:
  int day, month, year;

  static const std::vector<char> DAYS_IN_MONTHS;
  static const std::vector<std::string> MONTHS_IN_FRENCH;
  static const std::vector<std::string> DAYS_IN_FRENCH;

  bool static validDate(int day, int month, int year) {
    return day >= 1  && day <= daysInMonth(month, year) && month >= 1 && month <= 12;
  }
}; // Fin de Date

std::ostream & operator<<(std::ostream & fout, const Date & d);
std::istream & operator>>(std::istream & fin, Date & date);

bool operator==(const Date & d1, const Date & d2);
bool operator!=(const Date & d1, const Date & d2);
bool operator<(const Date & d1, const Date & d2);
bool operator<=(const Date & d1, const Date & d2);
bool operator>(const Date & d1, const Date & d2);
bool operator>=(const Date & d1, const Date & d2);



#endif // DATE_H_INCLUDED
