#include <iostream>
#include "src/Date.h"

using namespace std;

int main()
{
    int j=31, m=12, a=2019;

    Date today(j, m, a);

    today.prettyPrint();

    cout << today.toString() << endl;
    cout << today.dayOfYear() << endl;

    today.increment();
    cout << today.dayOfYear() << endl;
    cout << today.toString() << endl;

    cout << today.isBisextile() << endl;

    cout << today.dayInMonth() << endl;



    return 0;
}
