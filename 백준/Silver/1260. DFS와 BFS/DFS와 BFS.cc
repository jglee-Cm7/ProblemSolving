#include <bits/stdc++.h>
using namespace std;
int n, m, v;
vector<vector<int>> adj(1010);
vector<bool> vis(1010);
void bfs() {
  vis.assign(1010, 0);
  queue<int> q;
  q.push(v);
  vis[v] = 1;
  while (!q.empty()) {
    int cur = q.front();
    cout << cur << " ";
    q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }
  cout << "\n";
}
void dfs(int s) {
  cout << s << " ";
  vis[s] = 1;
  for (int nxt : adj[s]) {
    if (vis[nxt]) continue;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> v;
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());

  dfs(v);
  cout << "\n";
  bfs();
}