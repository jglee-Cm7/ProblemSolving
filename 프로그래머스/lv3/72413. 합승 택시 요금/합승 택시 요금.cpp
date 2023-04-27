#include <bits/stdc++.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<int> answer;
    vector<vector<int>> floyd(n + 1, vector<int>(n + 1, 0x3fffff));
    for(auto fare : fares) {
        floyd[fare[0]][fare[1]] = fare[2];
        floyd[fare[1]][fare[0]] = fare[2];
    }
    for(int i = 1; i <= n; i++)
        floyd[i][i] = 0;
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        }
    }
    for(int k = 1; k <= n; k++)
        answer.push_back(floyd[s][k] + floyd[k][a] + floyd[k][b]);
    
    return *min_element(answer.begin(), answer.end());
}