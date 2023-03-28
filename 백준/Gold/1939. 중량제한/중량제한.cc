#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[10010];
int n, m, x, y;
bool isPossible(int w) {
  vector<int> vis(n + 1, 0);
  vis[x] = 1;
  queue<int> q;
  q.push(x);

  while (!q.empty()) {
    int cur = q.front();
    if (cur == y) return true;
    q.pop();
    for (auto [nw, nx] : adj[cur]) {
      if (w > nw || vis[nx]) continue;
      if (nx == y) return true;
      vis[nx] = vis[cur] + 1;
      q.push(nx);
    }
  }

  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  cin >> x >> y;

  int s = 1;
  int e = 1'000'000'000;
  while (s <= e) {
    int mid = (s + e) / 2;
    if (isPossible(mid)) s = mid + 1;
    else e = mid - 1;
  }
  cout << e;
}