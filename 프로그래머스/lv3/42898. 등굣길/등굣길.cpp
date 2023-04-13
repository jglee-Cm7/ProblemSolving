#include <bits/stdc++.h>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(auto pos : puddles)
        dp[pos[1] - 1][pos[0] - 1] = -1;
    for(int i=0; i<n; i++) {
        if(dp[i][0] == -1) break;
        dp[i][0] = 1;
    }
    for(int i=0; i<m; i++) {
        if(dp[0][i] == -1) break;
        dp[0][i] = 1;
    }
    
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(dp[i][j] != 0) continue;
            int l = 0, u = 0;
            if(dp[i][j-1] != -1) l = dp[i][j-1] % 1'000'000'007;
            if(dp[i-1][j] != -1) u = dp[i-1][j] % 1'000'000'007;
            dp[i][j] = (l + u) % 1'000'000'007;
        }
    }
    
    return dp[n-1][m-1];
}