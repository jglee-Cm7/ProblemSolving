#include <bits/stdc++.h>
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

  int n;
  cin >> n;
  vector<tuple<int, int, int>> edges;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int w;
      cin >> w;
      if (i == j) continue;
      edges.push_back({w, i, j});
    }
  }
  sort(edges.begin(), edges.end());

  int cnt = 0;
  long long cost = 0;
  for (auto [w, a, b] : edges) {
    if (!isDiffGroup(a, b)) continue;
    cnt++;
    cost += (long long)w;
    if (cnt == n - 1) break;
  }

  cout << cost;
}