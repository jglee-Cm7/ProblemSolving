#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> hMap[m];
  vector<vector<int>> d(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int h;
      cin >> h;
      hMap[i].push_back(h);
    }
  }

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  priority_queue<tuple<int, int, int>> q;
  d[0][0] = 1;
  q.push({hMap[0][0], 0, 0});

  while (!q.empty()) {
    auto [h, x, y] = q.top();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if (hMap[nx][ny] < h) {
        if (d[nx][ny] == 0) q.push({hMap[nx][ny], nx, ny});
        d[nx][ny] += d[x][y];
      }
    }
  }

  // for (auto row : d) {
  //   for (auto col : row) {
  //     cout << col << " ";
  //   }
  //   cout << "\n";
  // }

  cout << d[m - 1][n - 1];
}