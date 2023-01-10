#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> floyd(n + 1, vector<int>(n + 1, 0));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> floyd[i][j];
      ans += floyd[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      for (int k = 1; k <= n; k++) {
        if (k == i || k == j) continue;
        if (floyd[i][j] == floyd[i][k] + floyd[k][j]) {
          ans -= floyd[i][j];
          break;
        }
        if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
          cout << "-1";
          return 0;
        }
      }
    }
  }
  cout << ans / 2;
}