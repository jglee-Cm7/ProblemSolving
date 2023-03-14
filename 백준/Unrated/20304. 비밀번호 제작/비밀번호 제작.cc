#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> vis(1050000, 0);
  queue<int> q;
  while (m--) {
    int pw;
    cin >> pw;
    vis[pw] = 1;
    q.push(pw);
  }

  int ans = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < 20; i++) {
      int x = cur ^ (1 << i);
      if (x > n) continue;
      if (vis[x]) continue;
      vis[x] = vis[cur] + 1;
      ans = max(ans, vis[x]);
      q.push(x);
    }
  }

  cout << ans - 1;
}