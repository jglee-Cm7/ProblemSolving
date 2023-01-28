#include <bits/stdc++.h>
using namespace std;
int board[1010][1010];
int vis[2][15][1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)s.length(); j++)
      board[i][j] = s[j] - '0';
  }

  queue<tuple<int, int, int, int>> q;
  vis[0][0][0][0] = 1;
  q.push({0, 0, 0, 0});

  while (!q.empty()) {
    auto [d, z, x, y] = q.front();
    q.pop();
    if (x == n - 1 && y == m - 1) {
      cout << vis[d][z][x][y];
      return 0;
    }
    bool flag = false;
    int nd = (d + 1) % 2;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == 0) {
        if (vis[nd][z][nx][ny] > 0) continue;
        vis[nd][z][nx][ny] = vis[d][z][x][y] + 1;
        q.push({nd, z, nx, ny});
      } else {
        if (z == k) continue;
        if (d == 0) {
          if (vis[nd][z + 1][nx][ny] > 0) continue;
          vis[nd][z + 1][nx][ny] = vis[d][z][x][y] + 1;
          q.push({nd, z + 1, nx, ny});
        } else {
          flag = true;
        }
      }
    }
    if (flag) {
      vis[nd][z][x][y] = vis[d][z][x][y] + 1;
      q.push({nd, z, x, y});
    }
  }

  cout << "-1";
}