#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, e;
  cin >> n >> e;
  vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
  vector<vector<pair<int, int>>> adj(n + 1);
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  int u, v;
  cin >> u >> v;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  for (int i = 1; i <= n; i++) {
    d[i][i] = 0;
    pq.push({0, i});
    while (!pq.empty()) {
      auto [w, cur] = pq.top();
      pq.pop();
      if (d[i][cur] != w) continue;
      for (auto [nw, nxt] : adj[cur]) {
        if (w + nw >= d[i][nxt]) continue;
        d[i][nxt] = w + nw;
        pq.push({d[i][nxt], nxt});
      }
    }
  }

  int ans = INF;
  if (d[1][u] != INF && d[u][v] != INF && d[v][n] != INF)
    ans = min(ans, d[1][u] + d[u][v] + d[v][n]);
  if (d[1][v] != INF && d[v][u] != INF && d[u][n] != INF)
    ans = min(ans, d[1][v] + d[v][u] + d[u][n]);

  if (ans == INF)
    cout << "-1";
  else
    cout << ans;
}