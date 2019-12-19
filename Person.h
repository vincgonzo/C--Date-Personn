#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED



#include "Date.h"

class Person {
public:
  Person() = default;
  Person(std::string fn, std::string ln, int d, int m, int y):
    firstName(fn), lastName(ln), dateOfBirth(d, m, y)
    { }

  Person(std::string fn, std::string ln, const Date date):
    firstName(fn), lastName(ln), dateOfBirth(date)
    { }

  Person & operator=(const Person & p) = default;

  std::string getFName() const { return firstName;   }
  std::string getLName() const { return lastName;    }
  Date getDateOfBirth()  const { return dateOfBirth; }

  bool operator==(const Person & p) const {
    return firstName == p.firstName &&
           lastName == p.lastName &&
           dateOfBirth == p.dateOfBirth;
  }

  bool operator!=(const Person & p) const {
    return !(*this == p);
  }

  bool operator<(const Person & p) const {
    return lastName + " " + firstName < p.lastName + " " + p.firstName;
  }

  bool operator<=(const Person & p) const {
    return *this < p || *this == p;
  }

  bool operator>(const Person & p) const {
    return !(*this <= p);
  }

  bool operator>=(const Person & p) const {
    return !(*this < p);
  }

  std::string toString() const {
    return firstName + " " + lastName +
           " ne le " + dateOfBirth.toString();
  }

  friend std::ostream & operator<<(std::ostream & fout, const Person & p) {
    fout << p.toString();
    return fout;
  }

  friend std::istream & operator>>(std::istream & fin, Person & p) {
    std::string fn, ln;
    Date date;
    fin >> fn;
    fin >> ln;
    fin >> date;
    p = Person(fn, ln, date);
    return fin;
  }

private:

  std::string firstName, lastName;
  Date dateOfBirth;
};


#endif // PERSON_H_INCLUDED
