#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k, n, m;
  cin >> k >> m >> n;
  vector<vector<int>> board(n, vector<int>(m));
  vector<vector<vector<int>>> vis(k + 1, vector<vector<int>>(n, vector<int>(m, -1)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int dxh[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  int dyh[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  deque<tuple<int, int, int>> q;
  vis[0][0][0] = 0;
  q.push_back({0, 0, 0});

  while (!q.empty()) {
    auto [x, y, z] = q.front();
    q.pop_front();
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == 1) continue;
      if (vis[z][nx][ny] > 0) continue;
      vis[z][nx][ny] = vis[z][x][y] + 1;
      q.push_back({nx, ny, z});
    }
    if (k == z) continue;
    for (int dir = 0; dir < 8; dir++) {
      int nx = x + dxh[dir];
      int ny = y + dyh[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == 1) continue;
      if (vis[z + 1][nx][ny] > 0) continue;
      vis[z + 1][nx][ny] = vis[z][x][y] + 1;
      q.push_back({nx, ny, z + 1});
    }
  }
  int ans = 0x7fffffff;
  for (int i = 0; i <= k; i++) {
    if (vis[i][n - 1][m - 1] >= 0) ans = min(ans, vis[i][n - 1][m - 1]);
  }
  if (ans == 0x7fffffff)
    cout << "-1";
  else
    cout << ans;
}