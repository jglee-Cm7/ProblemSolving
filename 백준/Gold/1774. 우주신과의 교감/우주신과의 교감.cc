#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> p(1005, -1);
int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}
bool isDiffGroup(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v])
    p[v] = u;
  else
    p[u] = v;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> loc(n + 1);
  vector<tuple<double, int, int>> edges;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    loc[i] = {x, y};
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double w = 0;
      if (loc[i].X == loc[j].X)
        w = (double)abs(loc[i].Y - loc[j].Y);
      else if (loc[i].Y == loc[j].Y)
        w = (double)abs(loc[i].X - loc[j].X);
      else
        w = sqrt(pow(abs(loc[i].X - loc[j].X), 2) +
                 pow(abs(loc[i].Y - loc[j].Y), 2));
      edges.push_back({w, i, j});
    }
  }
  sort(edges.begin(), edges.end());
  int cnt = 0;
  double ans = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (isDiffGroup(u, v)) cnt++;
  }
  for (auto [w, u, v] : edges) {
    if (!isDiffGroup(u, v)) continue;
    ans += w;
    cnt++;
    if (cnt == n - 1) break;
  }
  cout << fixed;
  cout.precision(2);
  cout << ans;
}