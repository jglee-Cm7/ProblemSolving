#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    int cnt = 0;
    
    for(string op : operations) {
        char code = op[0];
        int v = stoi(op.substr(2));
        if(code == 'I') q1.push(v), q2.push(v), cnt++;
        else if(code == 'D') {
            if(!q1.empty() && v == 1) q1.pop(), cnt--;
            else if(!q2.empty() && v == -1) q2.pop(), cnt--;
        }
        if(!cnt) {
            q1 = priority_queue<int>();
            q2 = priority_queue<int, vector<int>, greater<int>>();
        }
    }
    if(q1.empty()) answer.push_back(0);
    else answer.push_back(q1.top());
    
    if(q2.empty()) answer.push_back(0);
    else answer.push_back(q2.top());
    
    
    return answer;
}