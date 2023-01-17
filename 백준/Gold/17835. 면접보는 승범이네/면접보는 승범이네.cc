#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e10;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  vector<int> spot(k);
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[v].push_back({c, u});
  }
  for (int i = 0; i < k; i++)
    cin >> spot[i];

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
  ll mx = 0;
  ll ans = 0;
  vector<ll> d(n + 1, INF);
  for (int s : spot) {
    d[s] = 0;
    pq.push({0, s});
  }
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
  for (int i = 1; i <= n; i++) {
    if (d[i] > mx) {
      mx = d[i];
      ans = i;
    }
  }
  cout << ans << "\n" << mx;
}