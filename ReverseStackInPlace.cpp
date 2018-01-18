/*
Write a program to reverse a stack using recursion. 
You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S:
isEmpty(S)
push(S)
pop(S)
*/

#include <iostream>
#include <stack>

using namespace std;

void insertBottom(int p, stack<int> st) {
    if (st.empty())
        st.push(p);
    else {
        int x = st.top();
        st.pop();
        insertBottom(p, st);
        st.push(x);
    }
}

void reverse(stack<int> st) {
    if (!st.empty()) {
        int p = st.top();
        st.pop();
        reverse(st);
        
        insertBottom(p, st);
    }
}

int main()
{
    //push elements into the stack
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
     
    cout<<"Original Stack"<<endl;
    //print the elements of original stack
    cout<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<endl;
     
    //function to reverse the stack
    reverse(st);
    cout<<"Reversed Stack"<<endl;
     
    //storing values of reversed stack into a string for display
    while(!st.empty())
    {
        int p=st.top();
        st.pop();
        cout << p << " ";
    }
     
    return 0;
}
