#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < n; i++) {
    int v, u, w;
    cin >> v;
    while (1) {
      cin >> u;
      if (u == -1) break;
      cin >> w;
      adj[v].push_back({u, w});
      adj[u].push_back({v, w});
    }
  }

  int ans = 0;
  int st = 1;
  for (int i = 0; i < 2; i++) {
    vector<int> vis(n + 1, -1);
    deque<int> q;
    vis[st] = 0;
    q.push_back(st);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (auto [nxt, w] : adj[cur]) {
        if (vis[nxt] >= 0) continue;
        vis[nxt] = vis[cur] + w;
        q.push_back(nxt);
      }
    }
    for (int j = 1; j <= n; j++) {
      if (ans < vis[j]) {
        ans = vis[j];
        st = j;
      }
    }
  }

  cout << ans;
}