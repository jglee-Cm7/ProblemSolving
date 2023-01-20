#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> pre;
bool ban[501][501];

void banPath(int cur) {
  for (auto x : pre[cur]) {
    if (x != -1) {
      if (ban[x][cur]) continue;
      ban[x][cur] = 1;
      banPath(x);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    int n, m, s, e;
    cin >> n >> m;
    adj.clear();
    adj = vector<vector<pair<int, int>>>(n);
    if (n == 0 && m == 0) break;
    cin >> s >> e;
    while (m--) {
      int u, v, p;
      cin >> u >> v >> p;
      adj[u].push_back({p, v});
    }

    memset(ban, 0, sizeof ban);
    int mn = INF;
    while (1) {
      pre.clear();
      pre = vector<vector<int>>(n, vector<int>(1, -1));
      vector<int> d(n, INF);
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
      d[s] = 0;
      pq.push({0, s});

      while (!pq.empty()) {
        auto [w, cur] = pq.top();
        pq.pop();
        if (d[cur] != w) continue;
        for (auto [nw, nxt] : adj[cur]) {
          if (w + nw > d[nxt]) continue;
          if (ban[cur][nxt]) continue;
          if (w + nw == d[nxt])
            pre[nxt].push_back(cur);
          else {
            pre[nxt].clear();
            pre[nxt].push_back(cur);
            d[nxt] = w + nw;
            pq.push({d[nxt], nxt});
          }
        }
      }

      if (d[e] == INF) {
        cout << "-1\n";
        break;
      }

      banPath(e);

      if (mn == INF || mn == d[e]) {
        mn = d[e];
        continue;
      }
      if (d[e] > mn) {
        cout << d[e] << "\n";
        break;
      }
    }
  }
}