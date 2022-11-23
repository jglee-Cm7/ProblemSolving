#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int getDistance(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
  int mn = 200;
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)b.size(); j++) {
      int dis = abs(b[j].X - a[i].X) + abs(b[j].Y - a[i].Y) - 1;
      mn = min(mn, dis < 0 ? 0 : dis);
    }
  }

  return mn;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m[105][105];
  int vis[105][105];
  queue<pair<int, int>> q;
  vector<vector<pair<int, int>>> lands;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!vis[i][j] && m[i][j]) {
        q.push({i, j});
        vis[i][j] = 1;

        vector<pair<int, int>> land;
        while (!q.empty()) {
          pair<int, int> cur = q.front();
          land.push_back(cur);
          q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] != 0 || m[nx][ny] == 0) continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
          }
        }

        lands.push_back(land);
      }
    }
  }

  int ans = 200;
  for (int i = 0; i < (int)lands.size() - 1; i++) {
    for (int j = i + 1; j < (int)lands.size(); j++) {
      ans = min(ans, getDistance(lands[i], lands[j]));
    }
  }
  cout << ans;
}