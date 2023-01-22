#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, s, e;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> adj(n + 1);
  cin >> s >> e;
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({w, b});
    adj[b].push_back({w, a});
  }
  vector<int> tax(k + 1, 0);
  for (int i = 1; i <= k; i++)
    cin >> tax[i];

  vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq;
  d[0][s] = 0;
  pq.push({0, 0, s});

  while (!pq.empty()) {
    auto [w, c, cur] = pq.top();
    pq.pop();
    if (d[c][cur] != w || c >= n) continue;
    for (auto [wn, nxt] : adj[cur]) {
      if (w + wn >= d[c + 1][nxt]) continue;
      d[c + 1][nxt] = w + wn;
      pq.push({d[c + 1][nxt], c + 1, nxt});
    }
  }

  for (int i = 0; i <= k; i++) {
    int mn = INF;
    for (int j = 0; j <= n; j++) {
      if (d[j][e] == INF) continue;
      d[j][e] += (tax[i] * j);
      mn = min(mn, d[j][e]);
    }
    cout << mn << "\n";
  }
}