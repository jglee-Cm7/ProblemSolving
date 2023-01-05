#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
  vector<vector<int>> nxt(n + 1, vector<int>(n + 1, 0));
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    cost[a][b] = min(cost[a][b], c);
    nxt[a][b] = b;
  }
  for (int i = 1; i <= n; i++)
    cost[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (cost[i][k] + cost[k][j] < cost[i][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cout << (cost[i][j] == 0x3f3f3f3f ? 0 : cost[i][j]) << " ";
    cout << "\n";
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int next = nxt[i][j];
      if (next == 0) {
        cout << "0\n";
        continue;
      }
      vector<int> route;
      route.push_back(i);
      route.push_back(next);
      while (next != j) {
        next = nxt[next][j];
        route.push_back(next);
      }
      cout << route.size() << " ";
      for (int r : route)
        cout << r << " ";
      cout << "\n";
    }
  }
}