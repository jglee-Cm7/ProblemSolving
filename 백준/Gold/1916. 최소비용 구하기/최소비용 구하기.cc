#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
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
  }
  int s, e;
  cin >> s >> e;

  vector<int> d(n + 1, INF);
  d[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    if (d[cur] != w) continue;
    for (auto [nw, nxt] : adj[cur]) {
      if (w + nw >= d[nxt]) continue;
      d[nxt] = w + nw;
      pq.push({d[nxt], nxt});
    }
  }

  cout << d[e];
}