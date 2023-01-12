#include <bits/stdc++.h>
using namespace std;

int d[505][505];
int dt[505][505];
pair<int, int> c[505];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    fill(d[i], d[i] + n + 1, 0x3f3f3f3f);
    d[i][i] = 0;
    int w;
    cin >> w;
    c[i] = {w, i};
  }
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    d[a][b] = w;
    d[b][a] = w;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      dt[i][j] = max(c[i].first, c[j].first);
  }
  sort(c + 1, c + 1 + n);

  for (int l = 1; l <= n; l++) {
    int k = c[l].second;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int mx = max(dt[i][k], dt[k][j]);
        if (d[i][k] + d[k][j] + mx < d[i][j] + dt[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          dt[i][j] = max(dt[i][j], mx);
        }
      }
    }
  }

  while (q--) {
    int s, t;
    cin >> s >> t;
    if (d[s][t] == 0x3f3f3f3f)
      cout << "-1\n";
    else
      cout << d[s][t] + dt[s][t] << "\n";
  }
}