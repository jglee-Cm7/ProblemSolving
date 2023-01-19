#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  for (int i = 1; i <= m; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back({i, b});
    adj[b].push_back({i, a});
  }

  vector<ll> d(n + 1, INF);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
  d[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    if (d[cur] != w) continue;
    for (auto [nw, nxt] : adj[cur]) {
      if (nw <= w) nw += ((w - nw) / m) * m + m;
      if (nw >= d[nxt]) continue;
      d[nxt] = nw;
      pq.push({d[nxt], nxt});
    }
  }

  cout << d[n];
}