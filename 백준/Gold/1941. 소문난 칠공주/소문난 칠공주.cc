#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 5;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  vector<char> seat(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> seat[i * n + j];
  }
  vector<int> arr(n * n, 0);
  for (int i = n * n - 7; i < n * n; i++)
    arr[i] = 1;

  int ans = 0;

  do {
    int s = 0, sx = 0, sy = 0;
    for (int i = 0; i < n * n; i++) {
      grid[i / 5][i % 5] = arr[i];
      if (arr[i] == 1) {
        if (seat[i] == 'S') s++;
        sx = i / 5;
        sy = i % 5;
      }
    }

    if (s < 4) continue;

    int cnt = 0;
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    deque<pair<int, int>> q;
    vis[sx][sy] = 1;
    q.push_front({sx, sy});
    while (!q.empty()) {
      cnt++;
      auto [x, y] = q.front();
      q.pop_front();
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (grid[nx][ny] == 0) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        q.push_front({nx, ny});
      }
    }
    if (cnt == 7) ans++;
  } while (next_permutation(arr.begin(), arr.end()));

  cout << ans;
}