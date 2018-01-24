
/*
VMWare Propel Program Interview Question:
Given an array of employee scores - v, team size - t and set length - m,
a Manager chooses the highest scoring Employee from the first m or last m in the list.
Find the maximum score of the chosen team.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int t = 3;
    int m = 4;
    int n = v.size();
    priority_queue<int> lpq;
    priority_queue<int> rpq;
    int pq;
    int maxScore = 0;
    int l = 0, r = 0;
    
    for (l=0;l<m;l++) {
        lpq.push(v[l]);
    }
    
    for(r=n-1;r>=n-m;r--) {
        rpq.push(v[r]);
    }
    
    for (int i=0;i<t;i++) {
        if (lpq.top() >= rpq.top()) {
            cout << lpq.top() << endl;
            maxScore += lpq.top();
            lpq.pop();
            pq = 1;
        } 
        else {
            cout << rpq.top() << endl;
            maxScore += rpq.top();
            rpq.pop();
            pq = 2;
        }
        
        if (l < r) {
            if (pq == 1)
                lpq.push(v[l++]);
            else
                rpq.push(v[r--]);
        }
    }
    
    cout << "Max Score: " << maxScore << endl;
    
}
