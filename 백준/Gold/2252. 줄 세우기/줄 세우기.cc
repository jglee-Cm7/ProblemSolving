#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<int> deg(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    deg[v]++;
  }

  deque<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) q.push_back(i);
  }

  vector<int> ans;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    ans.push_back(cur);

    for (int nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push_back(nxt);
    }
  }

  for (int v : ans)
    cout << v << " ";
}