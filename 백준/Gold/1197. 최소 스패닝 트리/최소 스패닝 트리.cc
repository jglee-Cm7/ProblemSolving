#include <bits/stdc++.h>
using namespace std;

// Kruskal
vector<int> p(10'005, -1);
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

  int v, e;
  cin >> v >> e;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c, a, b});
  }

  sort(edges.begin(), edges.end());
  int cnt = 0;
  int ans = 0;
  for (auto [w, a, b] : edges) {
    if (!isDiffGroup(a, b)) continue;
    cnt++;
    ans += w;

    if (cnt == v - 1) break;
  }
  cout << ans;
}