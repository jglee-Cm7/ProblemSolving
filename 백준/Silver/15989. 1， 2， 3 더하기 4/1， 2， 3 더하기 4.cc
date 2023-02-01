#include <bits/stdc++.h>
using namespace std;
int dp[10001][7];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  dp[1][0] = 1;
  dp[2][0] = 1;
  dp[2][1] = 1;
  dp[3][0] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;

  for (int i = 4; i <= 10000; i++) {
    dp[i][0] = dp[i - 1][0];
    dp[i][1] = dp[i - 2][1];
    dp[i][2] = dp[i - 3][2];
    dp[i][3] = dp[i - 2][0] + dp[i - 2][3];
    dp[i][4] = dp[i - 3][0] + dp[i - 3][4];
    dp[i][5] = dp[i - 3][1] + dp[i - 3][5];
    dp[i][6] = dp[i - 3][3] + dp[i - 3][6];
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int j = 0; j < 7; j++)
      ans += dp[n][j];
    cout << ans << "\n";
  }
}