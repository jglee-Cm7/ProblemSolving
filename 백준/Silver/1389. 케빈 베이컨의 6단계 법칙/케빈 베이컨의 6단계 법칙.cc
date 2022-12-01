#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<int> score(n + 1);
  deque<int> q;

  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int mn = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    vector<int> vis(n + 1);
    vis[i] = 1;
    q.push_back(i);

    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();

      for (int v : adj[cur]) {
        if (vis[v]) continue;
        vis[v] = vis[cur] + 1;
        q.push_back(v);
        score[i] += vis[v] - 1;
      }
    }
    mn = min(mn, score[i]);
  }

  for (int i = 1; i <= n; i++)
    if (mn == score[i]) {
      cout << i;
      return 0;
    }
}