#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<vector<vector<int>>> floyd(
      n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0x3f3f3f3f)));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int v;
      cin >> v;
      floyd[0][i][j] = v == 0 ? 0x3f3f3f3f : v;
    }
  }
  for (int i = 1; i <= n; i++)
    floyd[0][i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        floyd[k][i][j] = min(floyd[k - 1][i][j], floyd[k - 1][i][k] + floyd[k - 1][k][j]);
      }
    }
  }

  while (q--) {
    int c, s, e;
    cin >> c >> s >> e;
    if (floyd[c - 1][s][e] == 0x3f3f3f3f)
      cout << "-1\n";
    else
      cout << floyd[c - 1][s][e] << "\n";
  }
}