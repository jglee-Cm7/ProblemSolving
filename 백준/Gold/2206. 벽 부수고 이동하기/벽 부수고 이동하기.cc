#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[1010][1010];
int vis[2][1010][1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      board[i][j] = s[j] - '0';
  }

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  vis[0][0][0] = 1;
  deque<tuple<int, int, int>> q;
  q.push_back({0, 0, 0});
  while (!q.empty()) {
    auto [k, i, j] = q.front();
    q.pop_front();
    for (int dir = 0; dir < 4; dir++) {
      int x = i + dx[dir];
      int y = j + dy[dir];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (board[x][y] == 1 && k == 1) continue;
      if (board[x][y] == 1 && k == 0) {
        if (vis[k + 1][x][y] > 0) continue;
        vis[k + 1][x][y] = vis[k][i][j] + 1;
        q.push_back({k + 1, x, y});
      }
      if (board[x][y] == 1 || vis[k][x][y] > 0) continue;
      vis[k][x][y] = vis[k][i][j] + 1;
      q.push_back({k, x, y});
    }
  }
  int ans = 0x7fffffff;
  for (int i = 0; i < 2; i++) {
    if (vis[i][n - 1][m - 1] > 0) ans = min(ans, vis[i][n - 1][m - 1]);
  }
  if (ans == 0x7fffffff)
    cout << "-1";
  else
    cout << ans;
}