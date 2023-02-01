#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  vector<int> d(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  d[1] = 0;
  q.push({0, 1});

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