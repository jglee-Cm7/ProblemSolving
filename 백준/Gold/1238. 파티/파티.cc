#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<pair<int, int>>> adj(n + 1);
  vector<vector<int>> d(n + 1, vector<int>(n + 1, 0x7fffffff));
  while (m--) {
    int a, b, t;
    cin >> a >> b >> t;
    adj[a].push_back({t, b});
  }

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

  int mx = 0;
  for (int i = 1; i <= n; i++)
    mx = max(mx, d[i][x] + d[x][i]);

  cout << mx;
}