#include <bits/stdc++.h>
using namespace std;
int vis[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int dx[3] = {-1, 1, 2};

  queue<int> q;
  vis[n] = 1;
  q.push(n);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int dir = 0; dir < 3; dir++) {
      int x = cur;
      if (dx[dir] == 2)
        x *= dx[dir];
      else
        x += dx[dir];
      if (x < 0 || x > 100000) continue;
      if (vis[x]) continue;
      vis[x] = vis[cur] + 1;
      if (vis[k] != 0) {
        cout << vis[k] - 1;
        return 0;
      }
      q.push(x);
    }
  }
}