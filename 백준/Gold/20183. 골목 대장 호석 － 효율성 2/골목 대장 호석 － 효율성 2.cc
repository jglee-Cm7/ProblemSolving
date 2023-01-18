#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  while (m--) {
    ll u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  vector<pair<ll, ll>> d(n + 1, {INF, INF});
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
  d[a] = {0, 0};
  pq.push({0, a, 0});
  while (!pq.empty()) {
    auto [w, cur, mxw] = pq.top();
    pq.pop();
    if (d[cur].first != w) continue;
    for (auto [nw, nxt] : adj[cur]) {
      ll nmxw = max(mxw, nw);
      if (w + nw >= d[nxt].first) continue;
      if (nmxw >= d[nxt].second) continue;
      if (w + nw > c) continue;
      d[nxt] = {(w + nw), nmxw};
      pq.push({d[nxt].first, nxt, nmxw});
    }
  }

  if (d[b].first == INF)
    cout << "-1";
  else
    cout << d[b].second;
}