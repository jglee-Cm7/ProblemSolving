#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> adj[n + 1];
  vector<int> d(n + 1, 0x7fffffff);
  vector<int> pre(n + 1);
  vector<vector<int>> path(n + 1, vector(n + 1, 0));
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({1, v});
    adj[v].push_back({1, u});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, 1});
  d[1] = 0;
  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    if (d[cur] != w) continue;
    for (auto [wn, nxt] : adj[cur]) {
      if (w + wn >= d[nxt]) continue;
      d[nxt] = w + wn;
      pre[nxt] = cur;
      pq.push({d[nxt], nxt});
    }
  }

  for (int i = 2; i <= n; i++) {
    int r = pre[i];
    path[i][i] = 1;
    while (r != 1) {
      path[i][r] = 1;
      r = pre[r];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int cnt = 0;
      for (int k = 1; k <= n; k++) {
        if (path[i][k] | path[j][k]) cnt++;
      }
      ans += cnt;
    }
  }
  cout << ans;
}