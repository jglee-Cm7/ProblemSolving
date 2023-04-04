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

  vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4, 0)));
  queue<pair<int, int>> q;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  vis[sx][sy][0] = 1;
  vis[sx][sy][1] = 1;
  vis[sx][sy][2] = 1;
  vis[sx][sy][3] = 1;
  q.push({sx, sy});
  board[sx][sy] = '.';
  int ans = -1;
  while (!q.empty()) {
    int size = q.size();
    while (size-- > 0) {
      auto [x, y] = q.front();
      q.pop();
      if (board[x][y] == 'C') {
        cout << ans;
        return 0;
      }
      for (int dir = 0; dir < 4; dir++) {
        int nx = x;
        int ny = y;
        while (1) {
          nx += dx[dir];
          ny += dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
          if (board[nx][ny] == '*') break;
          if (vis[nx][ny][dir]) break;
          vis[nx][ny][dir] = 1;
          q.push({nx, ny});
        }
      }
    }
    ans++;
  }
}