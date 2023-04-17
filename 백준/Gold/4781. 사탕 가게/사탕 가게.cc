#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    int n;
    double d;
    cin >> n >> d;
    if (n == 0) break;
    int m = (d * 100 + 0.5);
    vector<int> dp(m + 1, 0);
    vector<pair<int, int>> candy;
    for (int i = 0; i < n; i++) {
      int a;
      double b;
      cin >> a >> b;
      candy.push_back({a, (int)(b * 100 + 0.5)});
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        auto [cal, price] = candy[i];
        if (j - price < 0) continue;
        dp[j] = max(dp[j], dp[j - price] + cal);
      }
    }

    cout << dp[m] << "\n";
  }
}

// DP, 냅색