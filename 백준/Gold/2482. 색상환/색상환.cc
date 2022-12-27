#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j > i / 2) continue;
      if (j == 1)
        dp[i][j] = i;
      else
        dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;
    }
  }

  cout << dp[n][k];
}