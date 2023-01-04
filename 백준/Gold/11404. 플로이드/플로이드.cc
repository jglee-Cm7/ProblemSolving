#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    cost[a][b] = min(cost[a][b], w);
  }
  for (int i = 1; i <= n; i++)
    cost[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int s = 1; s <= n; s++) {
      // s -> t
      for (int t = 1; t <= n; t++) {
        // k를 경유해서 간다.
        if (cost[s][k] + cost[k][t] < cost[s][t])
          cost[s][t] = cost[s][k] + cost[k][t];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (cost[i][j] == 0x3f3f3f3f)
        cout << "0 ";
      else
        cout << cost[i][j] << " ";
    }
    cout << "\n";
  }
}