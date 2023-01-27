#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int arr[55][55];
int vis[55][55];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }

  int ans = 0;
  deque<pair<int, int>> q;
  while (1) {
    map<int, pair<int, int>> m; // group : <tot, count>
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (vis[i][j] > 0) continue;
        q.push_back({i, j});
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop_front();
          for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] > 0) continue;
            int gap = abs(arr[x][y] - arr[nx][ny]);
            if (gap >= l && gap <= r) {
              vis[x][y] = i * n + j + 1;
              vis[nx][ny] = i * n + j + 1;
              q.push_back({nx, ny});
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (vis[i][j]) {
          auto &[tot, cnt] = m[vis[i][j]];
          tot += arr[i][j];
          cnt++;
        }
      }
    }

    if (m.size() == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (vis[i][j]) arr[i][j] = m[vis[i][j]].first / m[vis[i][j]].second;
      }
    }
    for (int i = 0; i < n; i++)
      memset(vis[i], 0, sizeof(int) * n);
    ans++;
  }

  cout << ans;
}