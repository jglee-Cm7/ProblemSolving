#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> bd(h, vector<char>(w, 0));
    vector<pair<int, int>> ent;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char c;
        cin >> c;
        bd[i][j] = c;
        if (c != '*' && (i == 0 || i == h - 1 || j == 0 || j == w - 1))
          ent.push_back({i, j});
      }
    }
    set<char> ks;
    string key;
    cin >> key;
    for (auto k : key)
      ks.insert(k);
    int kc = key.length();
    int ans = 0;
    queue<pair<int, int>> q;


    while (1) {
      vector<vector<int>> vis(h, vector<int>(w, 0));
      for (auto [x, y] : ent) {
        if (bd[x][y] >= 'A' && bd[x][y] <= 'Z' &&
            ks.find(bd[x][y] + 32) == ks.end())
          continue;
        if (bd[x][y] >= 'a' && bd[x][y] <= 'z') {
          ks.insert(bd[x][y]);
        }
        q.push({x, y});
        vis[x][y] = 1;
      }
      int doc = 0;
      while (!q.empty()) {
        auto [x, y] = q.front();
        if (bd[x][y] == '$') doc++;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if (vis[nx][ny]) continue;
          if (bd[nx][ny] == '*') continue;
          if (bd[nx][ny] >= 'A' && bd[nx][ny] <= 'Z' &&
              ks.find(bd[nx][ny] + 32) == ks.end())
            continue;
          if (bd[nx][ny] >= 'a' && bd[nx][ny] <= 'z') {
            ks.insert(bd[nx][ny]);
          }
          vis[nx][ny] = vis[x][y] + 1;
          q.push({nx, ny});
        }
      }
      ans = max(ans, doc);
      if (kc == (int)ks.size()) break;
      kc = ks.size();
    }

    cout << ans << "\n";
  }
}