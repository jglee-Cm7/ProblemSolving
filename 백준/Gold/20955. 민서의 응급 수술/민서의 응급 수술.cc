#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> vis(n + 1);
  deque<int> q;
  int area = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    q.push_back(i);
    area++;
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        q.push_back(nxt);
      }
    }
  }
  int add = area > 1 ? area - 1 : 0;
  int minus = add + m > n - 1 ? add + m - (n - 1) : 0;
  cout << add + minus;
}