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
    int v1, v2;
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  int ans = -1;
  vis[1] = 1;
  q.push_back(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    if (vis[cur] < 4) ans++;

    for (auto v : adj[cur]) {
      if (vis[v]) continue;
      vis[v] = vis[cur] + 1;
      q.push_back(v);
    }
  }
  cout << ans;
}