#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;
  vector<vector<pair<int, int>>> adj(10010);
  for (int i = 1; i <= n; i++)
    adj[i - 1].push_back({1, i});

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  vector<int> d(n + 1, 0x7fffffff);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  d[0] = 0;
  q.push({0, 0});

  while (!q.empty()) {
    auto [w, cur] = q.top();
    q.pop();
    if (d[cur] != w) continue;
    for (auto [nw, nxt] : adj[cur]) {
      if (w + nw >= d[nxt]) continue;
      d[nxt] = w + nw;
      q.push({d[nxt], nxt});
    }
  }

  cout << d[n];
}