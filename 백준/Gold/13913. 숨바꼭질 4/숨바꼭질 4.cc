#include <bits/stdc++.h>
using namespace std;
int vis[200'000];
int pre[200'000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int dx[3] = {-1, 1, 2};

  memset(pre, -1, sizeof(int) * 200'000);
  vis[n] = 1;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == k) break;
    for (int dir = 0; dir < 3; dir++) {
      int x = cur;
      if (dx[dir] == 2)
        x += cur;
      else
        x += dx[dir];
      if (x < 0 || x >= 200'000) continue;
      if (vis[x] > 0) continue;
      vis[x] = vis[cur] + 1;
      pre[x] = cur;
      q.push({x});
    }
  }
  int ans = vis[k] - 1;
  vector<int> path;
  path.push_back(k);
  int p = pre[k];
  while (p != -1) {
    path.push_back(p);
    p = pre[p];
  }
  reverse(path.begin(), path.end());
  cout << ans << "\n";
  for (int p : path)
    cout << p << " ";
}