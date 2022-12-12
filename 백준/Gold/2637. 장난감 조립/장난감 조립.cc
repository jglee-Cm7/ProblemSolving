#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 1];
  vector<int> deg(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, k;
    cin >> x >> y >> k;
    adj[y].push_back({x, k});
    deg[x]++;
  }

  vector<vector<int>> part(n + 1, vector<int>(n + 1));
  deque<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.push_back(i);
      part[i][i] = 1;
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (auto [nxt, w] : adj[cur]) {
      deg[nxt]--;
      for (int i = 1; i <= n; i++) {
        part[nxt][i] += part[cur][i] * w;
      }
      if (deg[nxt] == 0) q.push_back(nxt);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (part[n][i] > 0) cout << i << " " << part[n][i] << "\n";
  }
}