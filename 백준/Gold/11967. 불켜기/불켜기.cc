#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj(10010);
vector<bool> vis(10010);
vector<bool> light(10010, 1);
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    adj[(x - 1) * n + y - 1].push_back((a - 1) * n + b - 1);
  }

  // for (int i = 0; i < n * n; i++) {
  //   cout << i << " : ";
  //   for (int aa : adj[i])
  //     cout << aa << " ";
  //   cout << "\n";
  // }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

  int ans = 1;
  bool exit = true;
  while (1) {
    exit = true;
    fill(vis.begin(), vis.end(), 0);
    q.push({0, 0});
    vis[0] = 1;
    light[0] = 0;
    while (!q.empty()) {
      auto [l, cur] = q.top();
      q.pop();
      if (cur == 0) {
      }
      if (light[cur] == 1) continue;
      // cout << cur << " visit! : ";
      int x = cur / n;
      int y = cur % n;
      for (int nxt : adj[cur]) {
        if (light[nxt] == 1) {
          light[nxt] = 0;
          // cout << nxt << " ";
          ans++;
          exit = false;
        }
      }
      // cout << "\n";
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int nxt = nx * n + ny;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        q.push({light[nxt], nxt});
      }
    }
    if (exit) break;
  }
  cout << ans;
}