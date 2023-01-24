#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<int>> cave(130, vector<int>(130, 0));
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  int cnt = 1;
  int n;
  while (1) {
    cin >> n;
    vector<int> d(n * n + 1, INF);
    vector<vector<pair<int, int>>> adj(n * n + 1);
    if (n == 0) break;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        cin >> cave[i][j];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int dir = 0; dir < 4; dir++) {
          int x = i + dx[dir];
          int y = j + dy[dir];
          if (x <= 0 || x > n || y <= 0 || y > n) continue;
          adj[(i - 1) * n + j].push_back({cave[x][y], (x - 1) * n + y});
        }
      }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    d[1] = cave[1][1];
    pq.push({cave[1][1], 1});

    while (!pq.empty()) {
      auto [w, cur] = pq.top();
      pq.pop();
      if (d[cur] != w) continue;
      for (auto [wn, nxt] : adj[cur]) {
        if (w + wn >= d[nxt]) continue;
        d[nxt] = w + wn;
        pq.push({d[nxt], nxt});
      }
    }

    cout << "Problem " << cnt++ << ": " << d[n * n] << "\n";
  }
}