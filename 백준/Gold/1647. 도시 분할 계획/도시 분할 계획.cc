#include <bits/stdc++.h>
using namespace std;

// kruskal
vector<int> p(100'005, -1);
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
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }
  sort(edges.begin(), edges.end());
  int cnt = 0;
  int ans = 0;
  int mx = 0;
  for (auto [w, u, v] : edges) {
    if (!isDiffGroup(u, v)) continue;
    cnt++;
    ans += w;
    mx = max(mx, w);
    if (cnt == n - 1) break;
  }

  cout << ans - mx;
}