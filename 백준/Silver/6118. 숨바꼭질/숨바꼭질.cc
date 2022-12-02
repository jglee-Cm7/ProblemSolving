#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> vis(n + 1);
  deque<int> q;
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vis[1] = 1;
  q.push_back(1);

  int mx = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (auto v : adj[cur]) {
      if (vis[v]) continue;
      vis[v] = vis[cur] + 1;
      q.push_back(v);
      mx = max(mx, vis[v]);
    }
  }
  int cnt = 0;
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    if (idx == 0 && mx == vis[i]) idx = i;
    if (mx == vis[i]) cnt++;
  }
  cout << idx << " " << mx - 1 << " " << cnt;
}