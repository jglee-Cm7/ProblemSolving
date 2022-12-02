#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 1);
    vector<int> vis(v + 1);
    vector<int> color(v + 1);
    deque<pair<int, int>> q;
    while (e--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    bool result = true;
    for (int i = 1; i <= v; i++) {
      if (!result) break;
      if (vis[i]) continue;
      vis[i] = 1;
      q.push_back({i, 1});
      color[i] = (1 % 2) + 1;

      while (!q.empty()) {
        if (!result) break;
        auto cur = q.front();
        q.pop_front();

        for (auto av : adj[cur.first]) {
          if (color[av] && color[av] == color[cur.first]) {
            result = false;
            break;
          }
          if (vis[av]) continue;
          vis[av] = 1;
          color[av] = ((cur.second + 1) % 2) + 1;
          q.push_back({av, cur.second + 1});
        }
      }
    }

    cout << (result ? "YES\n" : "NO\n");
  }
}