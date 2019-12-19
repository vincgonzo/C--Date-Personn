#include <iostream>
#include <algorithm>

#include "Date.h"
#include "Person.h"

using namespace std;

template <typename T>
void affiche(const vector<T> & v) {
  for(auto x: v)
    cout << x << endl;
  cout << endl;
}


int main() {
  Date d1;
  cout << "Nous sommes le:\n" << d1.toString() << endl;
  ++d1;
  cout << "Demain nous serons le:\n" << d1 << endl;

  Date d2 = Date(31, 12, d1.getYear());
  cout << "Le dernier jour de l'annee sera:\n" << d2++ << endl;
  Date d3 = d2;
  cout << "Le lendemain sera:\n" << d3 << endl;

  if(d2 != d3)
    cout << "Bizarre, ce message ne devrait pas apparaitre!\n";

  vector<Person> v = {
    {"John",    "Lennon",    {9, 10, 1940}},
    {"Paul",    "McCartney", {18, 6, 1942}},
    {"Georges", "Harrison",  {25, 2, 1943}},
    {"Ringo",   "Starr",     {7,  7, 1940}}
  };

  cout << "\n\nLes Beatles dans le desordre:\n";
  affiche(v);
  cout << "\nDans l'ordre des noms\n";
  sort(v.begin(), v.end());
  affiche(v);
  cout << "\nDans l'ordre des ages\n";
  sort(v.begin(), v.end(), [](const Person & p1, const Person & p2) {
       return p1.getDateOfBirth() > p2.getDateOfBirth();
  });
  affiche(v);
  cout << "\n\n";

  cout << "\nEntrez une personne"
          " (prenom, nom, jour mois annee de naissance):\n";
  Person p;
  cin >> p;
  cout << "La revoici:\n" << p << endl;

  cout << "\nNous allons maintenant construire une date illégale.\n";
  cout << "Enfoncez la touche Enter...\n\n";
  cin.ignore();
  cin.ignore();
  Date d5(29, 2, 2011);
}
