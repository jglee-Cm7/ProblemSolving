#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m, 0));
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  queue<pair<int, int>> q;

  int cnt = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!board[i][j] || vis[i][j]) continue;
      cnt++;
      q.push({i, j});
      vis[i][j] = 1;
      int area = 1;
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (!board[nx][ny] || vis[nx][ny]) continue;
          q.push({nx, ny});
          vis[nx][ny] = vis[x][y] + 1;
          area++;
        }
      }
      mx = max(mx, area);
    }
  }

  cout << cnt << "\n" << mx;
}