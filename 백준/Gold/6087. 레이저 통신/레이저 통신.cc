#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<vector<char>> board(n, vector<char>(m, 0));
  int sx, sy;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      board[i][j] = s[j];
      if (s[j] == 'C') sx = i, sy = j;
    }
  }

  vector<vector<int>> vis(n, vector<int>(m, 0));
  queue<pair<int, int>> q;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  q.push({sx, sy});
  board[sx][sy] = '.';
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (board[x][y] == 'C') {
      cout << vis[x][y] - 1;
      return 0;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = x;
      int ny = y;
      while (1) {
        nx += dx[dir], ny += dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if (board[nx][ny] == '*') break;
        if (!vis[nx][ny]) {
          vis[nx][ny] = vis[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
}