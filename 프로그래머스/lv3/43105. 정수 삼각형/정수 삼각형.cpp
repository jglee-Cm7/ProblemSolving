#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int m = triangle[n-1].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = triangle[0][0];
    for(int i=1; i<n; i++) dp[i][0] = dp[i-1][0] + triangle[i][0];
    for(int i=1; i<n; i++) {
        for(int j=1; j<i+1; j++)
            dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
    }
    
    answer = *max_element(dp[n-1].begin(), dp[n-1].end());
    return answer;
}