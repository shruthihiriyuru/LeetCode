/*
Given a number x, determine whether the given number is Armstrong number or not. 
A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if.

abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... 
*/

#include <iostream>
using namespace std;

int getOrder(int a) {
    int count = 0;
    while(a) {
        count++;
        a /= 10;
    }
    return count;
}

int power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    
    return x * power(x, n-1);
}

bool isArmstrong(int a) {
    int n = getOrder(a);
    int x = a;
    int sum = 0;
    while(x) {
        int r = x % 10;
        sum += power(r, n);
        x /= 10;
    }
    
    return sum == a;
}

int main() {
	int a = 153;
	cout << isArmstrong(a);
	return 0;
}
