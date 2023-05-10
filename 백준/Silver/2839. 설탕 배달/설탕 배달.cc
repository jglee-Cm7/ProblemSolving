#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> dp(n + 1, 0x3fffffff);
  dp[3] = 1;
  dp[5] = 1;
  for (int i = 6; i <= n; i++)
    dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);

  if (dp[n] >= 0x3fffffff)
    cout << -1;
  else
    cout << dp[n];
}