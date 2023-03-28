#include <bits/stdc++.h>
using namespace std;
int board[1010][1010];
int vis[1010][1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v;
      cin >> v;
      if (v != 0) vis[i][j] = 1;
      if (v == 1) q.push({i, j});
      board[i][j] = v;
    }
  }
  int mx = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] != 0 || vis[nx][ny]) continue;
      q.push({nx, ny});
      vis[nx][ny] = vis[x][y] + 1;
      mx = max(mx, vis[nx][ny] - 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) mx = -1;
  }
  cout << mx;
}