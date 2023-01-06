#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int v, e;
  cin >> v >> e;

  vector<vector<int>> floyd(v + 1, vector<int>(v + 1, INF));
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    floyd[a][b] = c;
  }
  for (int k = 1; k <= v; k++) {
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++)
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }
  }

  int ans = INF;
  for (int i = 1; i <= v; i++)
    ans = min(ans, floyd[i][i]);

  if (ans == INF) ans = -1;
  cout << ans;
}