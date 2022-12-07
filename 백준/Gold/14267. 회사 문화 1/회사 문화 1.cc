#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<int> p(n + 1);
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    if (v == -1) continue;
    adj[v].push_back(i);
    adj[i].push_back(v);
    p[i] = v;
  }

  for (int i = 0; i < m; i++) {
    int v, w;
    cin >> v >> w;
    ans[v] += w;
  }

  deque<int> q;
  q.push_back(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    for (int nxt : adj[cur]) {
      if (nxt == p[cur]) continue;
      q.push_back(nxt);
      ans[nxt] += ans[cur];
    }
  }

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
}