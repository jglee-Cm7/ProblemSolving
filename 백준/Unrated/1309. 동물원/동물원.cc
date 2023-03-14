#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n + 1; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 9901 + dp[i - 1][2] % 9901;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
  }

  int ans = (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
  cout << ans;
}

/*
  DP
*/