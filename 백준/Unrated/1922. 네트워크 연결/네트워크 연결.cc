#include <bits/stdc++.h>
using namespace std;

vector<int> p(1010, -1);
int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void unionGroup(int u, int v) {
  u = find(u), v = find(v);
  if (u < v)
    p[v] = u;
  else
    p[u] = v;
}

int isSameGroup(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c, a, b});
  }
  sort(edges.begin(), edges.end());

  int cnt = 0;
  int ans = 0;
  for (auto [c, a, b] : edges) {
    if (isSameGroup(a, b)) continue;
    unionGroup(a, b);
    cnt++;
    ans += c;
    if (cnt == n - 1) break;
  }
  cout << ans;
}