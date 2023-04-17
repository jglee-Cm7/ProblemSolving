#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    map<string, int> m;
    for(string gem : gems) m[gem]++;
    int count = m.size();
    vector<pair<int,int>> candi;
    
    map<string, int> t;
    int i = 0;
    int j = 0;
    for(; i < gems.size(); i++) {
        while(1) {
            if(t.size() == count) {
                candi.push_back({i+1, j});
                break;
            }
            if(j == gems.size()) break;
            t[gems[j++]]++;
        }
        t[gems[i]]--;
        if(t[gems[i]] == 0) t.erase(gems[i]);
    }
    i = 1, j = gems.size();
    for(auto [a, b] : candi) {
        if(b-a < j-i || (b-a == j-i && a < i)) {
            i = a, j = b;
        }
    }
    return {i, j};
}