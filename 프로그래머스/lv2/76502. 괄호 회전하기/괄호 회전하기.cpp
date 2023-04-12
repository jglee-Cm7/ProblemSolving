#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == ')') {
            if(st.empty() || st.top() != '(') return 0;
            else st.pop();
        } else if(c == '}') {
            if(st.empty() || st.top() != '{') return 0;
            else st.pop();
        } else if(c == ']') {
            if(st.empty() || st.top() != '[') return 0;
            else st.pop();
        } else st.push(c);
    }
    if(!st.empty()) return 0;
    return 1;
}

int solution(string s) {
    int answer = 0;
    int n = s.length();
    for(int i=0; i<n; i++) {
        if(check(s.substr(i) + s.substr(0, i))) answer++;
    }
    return answer;
}