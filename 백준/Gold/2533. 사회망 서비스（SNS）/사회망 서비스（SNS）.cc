#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1'000'005];
vector<int> vis(1'000'005);
vector<bool> ea(1'000'005);
bool dfs(int cur) {
  if (vis[cur]) return false;
  vis[cur] = 1;

  bool isLeaf = true;
  for (int nxt : adj[cur]) {
    if (vis[nxt]) continue;
    isLeaf = false;
    if (dfs(nxt)) {
      ea[cur] = true;
    }
    if (!ea[nxt]) ea[cur] = true;
  }
  return isLeaf;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (ea[i]) ans++;
  cout << ans;
}