#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  while (m--) {
    int to, from;
    cin >> to >> from;
    vector<int> vis(1005);
    deque<int> q;
    q.push_back(to);

    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      if (cur == from) break;

      for (auto nxt : adj[cur]) {
        if (vis[nxt.first]) continue;
        vis[nxt.first] = vis[cur] + nxt.second;
        q.push_back(nxt.first);
      }
    }
    cout << vis[from] << "\n";
  }
}