#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  deque<int> q;
  vector<vector<int>> ans(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;
      if (v) adj[i].push_back(j);
    }
  }

  for (int i = 0; i < n; i++) {
    vector<int> vis(n);
    q.push_back(i);

    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();

      for (auto v : adj[cur]) {
        if (vis[v]) continue;
        vis[v] = 1;
        q.push_back(v);
        ans[i][v] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }
}