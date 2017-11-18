/*
A Program to check if strings are rotations of each other or not
Given a string s1 and a string s2, 
write a snippet to say whether s2 is a rotation of s1 using only one call to strstr routine.
*/

#include <iostream>
#include <cstring>

using namespace std;

bool isRotation(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    
    if (n1 != n2)
        return false;
        
    string s = s1 + s1;
    
    const char *tmp = strstr(s.c_str(), s2.c_str());
    
    return (tmp != NULL);
}

int main() {
	//code
	string s1 = "ABCD";
	string s2 = "CDA";
	
	cout << isRotation(s1, s2);
	return 0;
}
