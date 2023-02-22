#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    for (int i = 1; i <= n; i++)
      d[i][i] = 0;
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      d[a][b] = min(d[a][b], c);
      d[b][a] = min(d[b][a], c);
    }
    while (w--) {
      int a, b, c;
      cin >> a >> b >> c;
      d[a][b] = min(d[a][b], -c);
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
        }
      }
    }

    bool no = 1;
    for (int i = 1; i <= n; i++)
      if (d[i][i] < 0) no = 0;
    if (no)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}