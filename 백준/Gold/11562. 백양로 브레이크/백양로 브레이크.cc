#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> floyd(n + 1, vector<int>(n + 1, INF));
  while (m--) {
    int u, v, b;
    cin >> u >> v >> b;
    floyd[u][v] = 0;
    floyd[v][u] = 0;
    if (!b) floyd[v][u] = 1;
  }
  for (int i = 1; i <= n; i++)
    floyd[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (floyd[i][k] + floyd[k][j] < floyd[i][j]) {
          floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        }
      }
    }
  }
  cin >> k;
  while (k--) {
    int u, v;
    cin >> u >> v;
    cout << floyd[u][v] << "\n";
  }
}