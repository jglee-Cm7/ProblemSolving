#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q(works.begin(), works.end());
    while(n--) {
        if(q.empty()) break;
        int v = q.top();
        q.pop();
        v--;
        if(v) q.push(v);
    }
    while(!q.empty()) {
        int v = q.top();
        q.pop();
        answer += v*v;
    }
    
    return answer;
}