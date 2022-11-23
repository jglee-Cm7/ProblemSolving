#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int vis[100005] = {0};
  int dx[3] = {1, -1, 2};
  queue<int> q;
  vis[n] = 1;
  q.push(n);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == k) {
      cout << vis[k] - 1;
      break;
    }
    for (int dir = 0; dir < 3; dir++) {
      int nx = cur + dx[dir];
      if (dx[dir] == 2) {
        nx = cur * 2;
      }
      if (nx < 0 || nx > 100000) continue;
      if (vis[nx] > 0 && vis[nx] <= vis[cur]) continue;
      if (dx[dir] == 2)
        vis[nx] = vis[cur];
      else
        vis[nx] = vis[cur] + 1;
      q.push(nx);
    }
  }
}