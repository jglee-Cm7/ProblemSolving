#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, s, e;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  vector<int> d(n + 1, 0x7fffffff);
  vector<int> pre(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  cin >> s >> e;
  d[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    if (d[cur] != w) continue;
    for (auto [nw, nxt] : adj[cur]) {
      if (w + nw < d[nxt]) {
        d[nxt] = w + nw;
        pq.push({d[nxt], nxt});
        pre[nxt] = cur;
      }
    }
  }
  vector<int> route;
  route.push_back(e);
  int r = pre[e];
  while (r) {
    route.push_back(r);
    r = pre[r];
  }
  reverse(route.begin(), route.end());
  cout << d[e] << "\n";
  cout << route.size() << "\n";
  for (int r : route)
    cout << r << " ";
}