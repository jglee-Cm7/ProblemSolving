#include <bits/stdc++.h>
using namespace std;
int dp[105][100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> items;
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    items.push_back({w, v});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      auto [w, v] = items[i - 1];
      if (j - w >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v);
    }
  }

  cout << dp[n][k];
}