#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[3010];
int cycle[3010];

void findCycle() {
  vector<int> vis(n + 1, 0);
  vector<int> prv(n + 1, 0);
  stack<int> s;
  s.push(1);
  while (!s.empty()) {
    auto x = s.top();
    s.pop();
    if (vis[x]) continue;
    vis[x] = 1;

    for (int nx : adj[x]) {
      if (vis[nx] && prv[x] != nx) {
        cycle[x] = 1;
        while (x != nx) {
          cycle[prv[x]] = 1;
          x = prv[x];
        }
        return;
      }
      if (vis[nx]) continue;
      prv[nx] = x;
      s.push(nx);
    }
  }
}

int bfs(int i) {
  vector<int> vis(n + 1, 0);
  queue<int> q;
  vis[i] = 1;
  q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int nx : adj[x]) {
      if (vis[nx]) continue;
      if (cycle[nx]) return vis[x];
      vis[nx] = vis[x] + 1;
      q.push(nx);
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  findCycle();
  for (int i = 1; i <= n; i++) {
    if (cycle[i])
      cout << "0 ";
    else
      cout << bfs(i) << " ";
  }
}