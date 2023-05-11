#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, w;
  cin >> t >> w;
  vector<vector<int>> plum(2, vector<int>(t + 1, 0));
  vector<vector<int>> dp(w + 1, vector<int>(t + 1, 0));
  for (int i = 1; i <= t; i++) {
    int v;
    cin >> v;
    if (v == 1) {
      plum[0][i] = 1;
      plum[1][i] = 0;
    } else {
      plum[0][i] = 0;
      plum[1][i] = 1;
    }
  }

  int mx = 0;
  dp[0][0] = 0;
  for (int j = 1; j <= t; j++) {
    dp[0][j] = dp[0][j - 1] + plum[0][j];
    mx = max(mx, dp[0][j]);
  }

  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= t; j++) {
      int p = plum[i % 2][j];
      dp[i][j] = max(dp[i - 1][j - 1] + p, dp[i][j - 1] + p);
      mx = max(mx, dp[i][j]);
    }
  }

  cout << mx;
}