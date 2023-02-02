#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(205, vector<int>(205, 0x3fffffff));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int c;
      cin >> c;
      if (i == j) dp[i][j] = 0;
      if (c == 1) {
        dp[i][j] = c;
        dp[j][i] = c;
      }
    }
  }
  vector<int> path;
  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    path.push_back(p);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
  }

  bool ans = 1;
  for (int i = 0; i < m - 1; i++) {
    if (dp[path[i]][path[i + 1]] == 0x3fffffff) {
      ans = 0;
      break;
    }
  }
  if (ans)
    cout << "YES";
  else
    cout << "NO";
}