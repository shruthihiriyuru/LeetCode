/*
  Finding maximum length of subarray having maximum sum
*/

#include <iostream>
using namespace std;

int main() {
	int a[] = {2, 3, -4, 4};
	int maxEndingHere = a[0], maxTotal = a[0], start = 0, maxLen = 1;
	
	for (int i=1;i<sizeof(a)/sizeof(a[0]);i++) {
	   if (a[i] > maxEndingHere+a[i]) {
	       start = i;
	       maxEndingHere = a[i];
	   }
	   else {
	       maxEndingHere = maxEndingHere + a[i];
	   }
	   if (maxEndingHere >= maxTotal) {
	       maxLen = max(maxLen, i-start+1);
	       maxTotal = maxEndingHere;
	   }
	}
	
	cout << "maxLen: " << maxLen << " maxTotal: " << maxTotal;
	return 0;
}
