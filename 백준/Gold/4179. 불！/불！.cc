#include <bits/stdc++.h>
using namespace std;
char maze[1010][1010];
int visF[1010][1010];
int visJ[1010][1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  queue<pair<int, int>> qf;
  queue<pair<int, int>> qj;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char c;
      cin >> c;
      maze[i][j] = c;
      if (c == 'F') {
        qf.push({i, j});
        visF[i][j] = 1;
      }
      if (c == 'J') {
        qj.push({i, j});
        visJ[i][j] = 1;
      }
    }
  }
  while (!qf.empty()) {
    auto [x, y] = qf.front();
    qf.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (visF[nx][ny]) continue;
      if (maze[nx][ny] != '.') continue;
      visF[nx][ny] = visF[x][y] + 1;
      qf.push({nx, ny});
    }
  }
  while (!qj.empty()) {
    auto [x, y] = qj.front();
    qj.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nt = visJ[x][y] + 1;
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
        cout << visJ[x][y];
        return 0;
      };
      if (visJ[nx][ny]) continue;
      if (maze[nx][ny] != '.') continue;
      if (visF[nx][ny] != 0 && visF[nx][ny] <= nt) continue;
      visJ[nx][ny] = nt;
      qj.push({nx, ny});
    }
  }
  cout << "IMPOSSIBLE";
}