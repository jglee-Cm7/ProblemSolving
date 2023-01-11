#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t;
  cin >> n >> m >> t;
  vector<vector<int>> floyd(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
  while (m--) {
    int u, v, h;
    cin >> u >> v >> h;
    floyd[u][v] = h;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        floyd[i][j] = min(floyd[i][j], max(floyd[i][k], floyd[k][j]));
      }
    }
  }
  while (t--) {
    int s, e;
    cin >> s >> e;
    if (floyd[s][e] == 0x3f3f3f3f)
      cout << "-1\n";
    else
      cout << floyd[s][e] << "\n";
  }
}