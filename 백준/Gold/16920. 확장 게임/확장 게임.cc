#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int board[1010][1010];
int vis[1010][1010];
int step[15];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<tuple<int, int, int>> q[15];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;
  for (int i = 1; i <= p; i++)
    cin >> step[i];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)s.length(); j++) {
      if (s[j] == '.')
        board[i][j] = 0;
      else if (s[j] == '#')
        board[i][j] = -1;
      else {
        int v = s[j] - '0';
        board[i][j] = v;
        vis[i][j] = v;
        q[v].push({i, j, 0});
      }
    }
  }

  while (1) {
    bool exit = 1;
    for (int i = 1; i <= p; i++) {
      queue<tuple<int, int, int>> nq;
      while (!q[i].empty()) {
        auto [x, y, k] = q[i].front();
        q[i].pop();

        if (k >= step[i]) {
          nq.push({x, y, 0});
          continue;
        }

        for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (board[nx][ny] == 0) {
            board[nx][ny] = i;
            vis[nx][ny] = i;
            q[i].push({nx, ny, k + 1});
            exit = 0;
          }
        }
      }
      q[i] = nq;
    }

    if (exit) break;
  }

  vector<int> ans(p + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      ans[vis[i][j]]++;
  }
  for (int i = 1; i <= p; i++)
    cout << ans[i] << " ";
}