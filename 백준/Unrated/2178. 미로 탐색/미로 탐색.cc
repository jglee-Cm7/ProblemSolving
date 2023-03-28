#include <bits/stdc++.h>
using namespace std;
int board[105][105];
int vis[105][105];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      board[i][j] = s[j] - '0';
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = 1;

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
    }
  }

  cout << vis[n - 1][m - 1];
}