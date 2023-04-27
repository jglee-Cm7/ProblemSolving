#include <bits/stdc++.h>

using namespace std;

int n;
map<string, vector<pair<string, bool>>> adj;

void func(int k, string st, vector<string>& answer) {
    if(k == n) return;
    
    for(auto& [en, used] : adj[st]) {
        if(used) continue;
        answer.push_back(en);
        used = true;
        func(k+1, en, answer);
        if(answer.size() == n + 1) return;
        answer.pop_back();
        used = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = tickets.size();
    for(auto ticket: tickets)
        adj[ticket[0]].push_back({ticket[1], 0});
    
    for(auto& [key, value] : adj)
        sort(value.begin(), value.end());
    
    answer.push_back("ICN");
    func(0, "ICN", answer);
    
    return answer;
}