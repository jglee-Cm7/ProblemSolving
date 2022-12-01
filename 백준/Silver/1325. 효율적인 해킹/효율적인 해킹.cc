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
    adj[b].push_back(a);
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> vis(n + 1);
    vis[i] = 1;
    q.push_back(i);
    int cnt = 0;

    while (!q.empty()) {
      cnt++;
      int cur = q.front();
      q.pop_front();

      for (auto v : adj[cur]) {
        if (vis[v]) continue;
        vis[v] = 1;
        q.push_back(v);
      }
    }
    score[i] = cnt;
    mx = max(mx, cnt);
  }

  for (int i = 1; i <= n; i++) {
    if (mx == score[i]) cout << i << " ";
  }
}