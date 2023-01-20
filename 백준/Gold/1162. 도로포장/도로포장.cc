#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = LLONG_MAX;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  vector<vector<ll>> d(k + 1, vector<ll>(n + 1, INF));
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;

  d[0][1] = 0;
  pq.push({0, 0, 1});

  while (!pq.empty()) {
    auto [w, ck, cur] = pq.top();
    pq.pop();
    if (d[ck][cur] != w) continue;
    for (auto [nw, nxt] : adj[cur]) { // 5, 2
      if (w + nw < d[ck][nxt]) {
        d[ck][nxt] = w + nw;
        pq.push({d[ck][nxt], ck, nxt});
      }
      if (ck < k && w < d[ck + 1][nxt]) {
        d[ck + 1][nxt] = w;
        pq.push({d[ck + 1][nxt], ck + 1, nxt});
      }
    }
  }

  // for (int i = 0; i <= k; i++) {
  //   for (int j = 1; j <= n; j++)
  //     cout << d[i][j] << " ";
  //   cout << "\n";
  // }

  ll mn = INF;
  for (int i = 0; i <= k; i++) {
    mn = min(mn, d[i][n]);
  }
  cout << mn;
}