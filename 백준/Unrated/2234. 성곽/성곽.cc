#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> m >> n;
  vector<vector<int>> board(n, vector<int>(m, 0));
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {-1, 0, 1, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  int rCnt = 0;
  vector<int> areas(2510, 0);
  int rMax = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j]) continue;
      rCnt++;
      int area = 0;
      vis[i][j] = rCnt;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        area++;
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          int wall = pow(2, dir);
          if (board[x][y] & wall) continue;
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vis[nx][ny]) continue;
          vis[nx][ny] = rCnt;
          q.push({nx, ny});
        }
      }
      areas[rCnt] = area;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int dir = 0; dir < 4; dir++) {
        int x = i + dx[dir];
        int y = j + dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (vis[i][j] == vis[x][y]) continue;
        rMax = max(rMax, areas[vis[i][j]] + areas[vis[x][y]]);
      }
    }
  }

  int rArea = *max_element(areas.begin(), areas.end());
  cout << rCnt << "\n" << rArea << "\n" << rMax;
}