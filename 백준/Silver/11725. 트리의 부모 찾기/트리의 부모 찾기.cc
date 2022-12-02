#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> parent(100005);
void dfs(int cur) {
  for (auto v : adj[cur]) {
    if (parent[cur] == v) continue;
    parent[v] = cur;
    dfs(v);
  }
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

  // dfs(1);
  deque<int> q;
  q.push_back(1);

  while (!q.empty()) {
    int cur = q.back();
    q.pop_back();
    for (int v : adj[cur]) {
      if (parent[cur] == v) continue;
      parent[v] = cur;
      q.push_back(v);
    }
  }

  for (int i = 2; i <= n; i++)
    cout << parent[i] << "\n";
}
