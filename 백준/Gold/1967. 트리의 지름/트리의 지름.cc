#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> adj[n + 1];
  for (int i = 1; i < n; i++) {
    int p, c, w;
    cin >> p >> c >> w;
    adj[p].push_back({c, w});
    adj[c].push_back({p, w});
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> vis(n + 1, -1);
    deque<int> q;
    vis[i] = 0;
    q.push_back(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (auto [nxt, w] : adj[cur]) {
        if (vis[nxt] >= 0) continue;
        vis[nxt] = vis[cur] + w;
        q.push_back(nxt);
      }
    }
    ans = max(ans, *max_element(vis.begin(), vis.end()));
  }

  cout << ans;
}