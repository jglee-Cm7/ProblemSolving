#include <bits/stdc++.h>
using namespace std;
int arr[1010][1010];
int vis[1010][1010];
int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  queue<pair<int, int>> q;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) {
        q.push({i, j});
        vis[i][j] = 1;
      }
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny]) continue;
      if (arr[nx][ny] == 0) continue;
      vis[nx][ny] = vis[x][y] + 1;
      q.push({nx, ny});
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0)
        cout << "0 ";
      else
        cout << vis[i][j] - 1 << " ";
    }
    cout << "\n";
  }
}