#include <bits/stdc++.h>
using namespace std;
vector<int> p(1005, -1);
vector<bool> plant(1005, false);
int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return true;
  if (plant[u] && plant[v]) return true;
  if (p[u] == p[v]) p[u]--;
  if (plant[u])
    p[v] = u;
  else if (plant[v])
    p[u] = v;
  else {
    if (p[u] < p[v])
      p[v] = u;
    else
      p[v] = u;
  }

  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < k; i++) {
    int u;
    cin >> u;
    plant[u] = true;
  }
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }

  sort(edges.begin(), edges.end());

  int ans = 0;
  for (auto [w, u, v] : edges) {
    if (merge(u, v)) continue;
    ans += w;
  }

  cout << ans;
}