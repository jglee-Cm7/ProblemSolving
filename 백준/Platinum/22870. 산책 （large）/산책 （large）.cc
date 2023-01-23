#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;

int n, m, s, e;
vector<vector<pair<int, int>>> adj(200'010);
vector<bool> isUsed(200'010);

vector<int> dijstra(int s, int e) {
  vector<int> d(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  d[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();
    if (d[cur] != w) continue;
    for (auto [nxt, wn] : adj[cur]) {
      if (isUsed[nxt]) continue;
      if (w + wn >= d[nxt]) continue;
      d[nxt] = w + wn;
      pq.push({d[nxt], nxt});
    }
  }

  return d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  cin >> s >> e;
  for (int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());

  vector<int> ds = dijstra(s, e);
  vector<int> de = dijstra(e, s);
  vector<int> path;

  int ps = s;
  int pe = e;
  int dist = ds[ps];
  while (ps != pe) {
    for (auto [nxt, w] : adj[ps]) {
      if (dist + w + de[nxt] == ds[pe]) {
        path.push_back(nxt);
        dist += w;
        ps = nxt;
        break;
      }
    }
  }
  for (auto p : path)
    isUsed[p] = 1;

  de = dijstra(e, s);
  cout << ds[e] + de[s];
}