#include <bits/stdc++.h>
using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 0;
    int n = routes.size();
    vector<bool> used(n, 0);
    sort(routes.begin(), routes.end(), [](const vector<int> a, const vector<int> b) {
        return a[1] < b[1];
    });
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        used[i] = 1;
        answer++;
        
        for(int j = i + 1; j < n; j++) {
            if(routes[i][1] < routes[j][0]) break;
            used[j] = 1;
        }
        
    }
    return answer;
}