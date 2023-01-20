#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = LLONG_MAX;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  vector<priority_queue<ll>> d(n + 1);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
  d[1].push(0);
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    for (auto [nw, nxt] : adj[cur]) {
      if ((int)d[nxt].size() < k || w + nw < d[nxt].top()) {
        d[nxt].push(w + nw);
        pq.push({w + nw, nxt});
      }
      if ((int)d[nxt].size() > k) d[nxt].pop();
    }
  }

  for (int i = 1; i <= n; i++) {
    if ((int)d[i].size() != k)
      cout << "-1\n";
    else
      cout << d[i].top() << "\n";
  }
}