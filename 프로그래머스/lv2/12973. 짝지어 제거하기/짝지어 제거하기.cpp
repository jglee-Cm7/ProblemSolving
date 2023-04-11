#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    if(s.size() % 2) return 0;
    stack<char> st;
    for(char c : s) {
        if(st.empty()) {
            st.push(c);
            continue;
        }
        if(st.top() == c) st.pop();
        else st.push(c);
    }
    
    if(!st.empty()) return 0;
    else return 1;
}