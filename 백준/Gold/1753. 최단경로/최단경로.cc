#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int v, e, s;
  cin >> v >> e >> s;
  vector<vector<pair<int, int>>> adj(v + 1);
  vector<int> d(v + 1, 0x7fffffff);
  while (e--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  d[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    if (d[cur] != w) continue;
    for (auto [nxt, nxtW] : adj[cur]) {
      if (w + nxtW < d[nxt]) {
        d[nxt] = w + nxtW;
        pq.push({d[nxt], nxt});
      }
    }
  }
  for (int i = 1; i <= v; i++)
    if (d[i] == 0x7fffffff)
      cout << "INF\n";
    else
      cout << d[i] << "\n";
}