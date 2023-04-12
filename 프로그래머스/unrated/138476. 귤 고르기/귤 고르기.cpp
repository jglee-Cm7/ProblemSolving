#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    for(int t : tangerine) m[t]++;
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const pair<int, int> a , const pair<int, int> b) {
        return a.second > b.second;
    });
    
    for(auto [key, value] : v) {
        answer++;
        k -= value;
        if(k <= 0) break;
    }
    
    return answer;
}