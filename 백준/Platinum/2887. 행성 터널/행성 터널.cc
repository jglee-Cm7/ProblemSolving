#include <bits/stdc++.h>
using namespace std;
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

  int n;
  cin >> n;
  vector<tuple<int, int, int, int>> pnt(n);
  vector<tuple<int, int, int>> edges;

  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    pnt[i] = {i + 1, x, y, z};
  }

  for (int k = 0; k < 3; k++) {
    switch (k) {
    case 0:
      sort(pnt.begin(), pnt.end(), [](const auto &a, const auto &b) -> bool {
        int idx1, x1, y1, z1, idx2, x2, y2, z2;
        tie(idx1, x1, y1, z1) = a;
        tie(idx2, x2, y2, z2) = b;
        return x1 < x2;
      });
      break;
    case 1:
      sort(pnt.begin(), pnt.end(), [](const auto &a, const auto &b) -> bool {
        int idx1, x1, y1, z1, idx2, x2, y2, z2;
        tie(idx1, x1, y1, z1) = a;
        tie(idx2, x2, y2, z2) = b;
        return y1 < y2;
      });
      break;
    case 2:
      sort(pnt.begin(), pnt.end(), [](const auto &a, const auto &b) -> bool {
        int idx1, x1, y1, z1, idx2, x2, y2, z2;
        tie(idx1, x1, y1, z1) = a;
        tie(idx2, x2, y2, z2) = b;
        return z1 < z2;
      });
      break;
    }
    for (int i = 0; i < n - 1; i++) {
      int idx1, x1, y1, z1, idx2, x2, y2, z2;
      tie(idx1, x1, y1, z1) = pnt[i];
      tie(idx2, x2, y2, z2) = pnt[i + 1];
      int w = min(abs(x1 - x2), abs(y1 - y2));
      w = min(w, abs(z1 - z2));
      edges.push_back({w, idx1, idx2});
    }
  }

  sort(edges.begin(), edges.end());
  long long ans = 0;
  int cnt = 0;
  for (auto [w, u, v] : edges) {
    if (!isDiffGroup(u, v)) continue;
    cnt++;
    ans += (long long)w;
    if (cnt == n - 1) break;
  }
  cout << ans;
}