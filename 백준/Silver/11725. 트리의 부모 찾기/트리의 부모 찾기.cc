#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100005);
vector<int> parent(100005);
vector<int> vis(100005);
void dfs(int cur, int p) {
  if (vis[cur]) return;
  vis[cur] = 1;
  parent[cur] = p;
  for (auto v : adj[cur])
    dfs(v, cur);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0);

  for (int i = 2; i <= n; i++)
    cout << parent[i] << "\n";
}