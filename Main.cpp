#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
    Set today;
    today.addElement(12);
    today.addElement(10);
    today.addElement(18);
    today.addElement(14);
    today.addElement(20);
    //today.removeElement(20);
    today.displaySet();

    Set tomorrow;
    tomorrow.addElement(12);
    tomorrow.addElement(10);
    tomorrow.addElement(1);
    tomorrow.displaySet();

    cout << today.isSubset(tomorrow) << endl;
    cout << tomorrow.isSubset(today) << endl;

    today.displayCrossProduct(tomorrow);
    tomorrow.displayCrossProduct(today);

    Set unionSet{ today.calcUnion(tomorrow) };
    unionSet.displaySet();
    Set interSet{ today.calcIntersection(tomorrow) };
    interSet.displaySet();
    Set diffSet{ today.calcDifference(tomorrow) };
    diffSet.displaySet();

    Set Abdullah{ diffSet };
    Abdullah.displaySet();
    
    return 0;
}