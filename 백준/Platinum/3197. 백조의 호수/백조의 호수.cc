#include <bits/stdc++.h>
using namespace std;
string rake[1505];
int ice[1505][1505];
int vis[1505][1505];
int r, c, x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void melting() {
  queue<pair<int, int>> q;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (rake[i][j] == '.' || rake[i][j] == 'L') continue;
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (rake[nx][ny] == '.' || rake[nx][ny] == 'L') {
          q.push({i, j});
          ice[i][j] = 1;
          break;
        }
      }
    }
  }
  while (!q.empty()) {
    auto [cx, cy] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (ice[nx][ny]) continue;
      if (rake[nx][ny] != 'X') continue;
      ice[nx][ny] = ice[cx][cy] + 1;
      q.push({nx, ny});
    }
  }

  // for (int i = 0; i < r; i++) {
  //   for (int j = 0; j < c; j++)
  //     cout << ice[i][j] << " ";
  //   cout << "\n";
  // }
  // cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> rake[i];
    for (int j = 0; j < c; j++)
      if (rake[i][j] == 'L') x = i, y = j;
  }

  // for (int i = 0; i < r; i++) {
  //   for (int j = 0; j < c; j++)
  //     cout << rake[i][j] << " ";
  //   cout << "\n";
  // }
  // cout << "\n";
  melting();
  int cnt = 0;
  queue<pair<int, int>> q;
  queue<pair<int, int>> nq;
  nq.push({x, y});
  vis[x][y] = 1;
  while (1) {
    while (!nq.empty()) {
      auto [nx, ny] = nq.front();
      nq.pop();
      q.push({nx, ny});
    }

    while (!q.empty()) {
      auto [cx, cy] = q.front();
      q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (vis[nx][ny]) continue;
        if (rake[nx][ny] == 'L') {
          cout << cnt;
          return 0;
        }
        if (ice[nx][ny] <= cnt) {
          vis[nx][ny] = cnt + 1;
          q.push({nx, ny});
        } else if (ice[nx][ny] == cnt + 1) {
          nq.push({nx, ny});
          vis[nx][ny] = cnt + 1;
        }
      }
    }

    cnt++;
  }
}