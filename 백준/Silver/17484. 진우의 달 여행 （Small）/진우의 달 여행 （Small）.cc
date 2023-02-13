#include <bits/stdc++.h>
using namespace std;
int board[6][6];
int dp[6][6][3];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++)
      dp[0][i][j] = board[0][i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 3; k++)
        dp[i][j][k] = 0x7fffffff;
      if (j - 1 >= 0)
        dp[i][j][0] = min(dp[i - 1][j - 1][1] + board[i][j],
                          dp[i - 1][j - 1][2] + board[i][j]);
      dp[i][j][1] =
          min(dp[i - 1][j][0] + board[i][j], dp[i - 1][j][2] + board[i][j]);
      if (j + 1 < m)
        dp[i][j][2] = min(dp[i - 1][j + 1][0] + board[i][j],
                          dp[i - 1][j + 1][1] + board[i][j]);
    }
  }
  int ans = 0x7fffffff;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++)
      ans = min(ans, dp[n - 1][i][j]);
  }
  cout << ans;
}