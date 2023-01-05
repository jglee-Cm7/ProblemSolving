#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, r;
  cin >> n >> m >> r;
  vector<int> item(n + 1);
  vector<vector<int>> floyd(n + 1, vector<int>(n + 1, 100));
  for (int i = 1; i <= n; i++)
    cin >> item[i];
  for (int i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    floyd[a][b] = l;
    floyd[b][a] = l;
  }
  for (int i = 1; i <= n; i++)
    floyd[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      if (floyd[i][j] <= m) mx += item[j];
    }
    ans = max(ans, mx);
  }
  cout << ans;
}