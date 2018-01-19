/*
Assumin the question:
Given an array that represents balloons with points:
You have to maximumize points such that when when u burst ai, ai - 1 and ai + 1 are automatically burst.
Now by bursting such ai gather maximum points.
*/


#include <iostream>
using namespace std;

int maxPoints(int b[], int l, int r) {
    if ( l > r)
        return 0;
        
    return max((b[l] + maxPoints(b, l+2, r)), maxPoints(b, l+1, r));
}

int main () {
    int balloons[] = {8, 9, 6, 1, 7, 4};
    int n = sizeof(balloons)/sizeof(balloons[0]);
    cout << maxPoints(balloons, 0, n-1);
}
