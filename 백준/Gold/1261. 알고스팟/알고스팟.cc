#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  string s[105];
  int maze[105][105];
  for (int i = 0; i < m; i++)
    cin >> s[i];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      maze[i][j] = s[i][j] - '0';
  }

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  vector<vector<pair<int, int>>> adj(n * m + 1);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int dir = 0; dir < 4; dir++) {
        int x = dx[dir] + i;
        int y = dy[dir] + j;
        if (x >= m || x < 0 || y >= n || y < 0) continue;
        if (maze[x][y] == 0) {
          adj[(i * n) + j + 1].push_back({0, (x * n) + y + 1});
        } else {
          adj[(i * n) + j + 1].push_back({1, (x * n) + y + 1});
        }
      }
    }
  }

  vector<int> d(n * m + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  d[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    if (d[cur] != w) continue;
    for (auto [nw, nxt] : adj[cur]) {
      if (w + nw >= d[nxt]) continue;
      d[nxt] = w + nw;
      pq.push({d[nxt], nxt});
    }
  }

  cout << d[n * m];
}