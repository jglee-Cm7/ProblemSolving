#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> map(n);
  for (int i = 0; i < n; i++)
    cin >> map[i];
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int>> q;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 'W') continue;
      vector<vector<int>> vis(n, vector<int>(m, 0));
      int mx = 1;
      vis[i][j] = 1;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vis[nx][ny] || map[nx][ny] == 'W') continue;
          vis[nx][ny] = vis[x][y] + 1;
          q.push({nx, ny});
          if (vis[nx][ny] > mx) {
            mx = vis[nx][ny];
          }
        }
      }
      ans = max(ans, mx);
    }
  }
  cout << ans - 1;
}