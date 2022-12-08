#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<int> deg(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    deg[b]++;
  }

  set<int> s;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) s.insert(i);
  }
  while (!s.empty()) {
    int cur = *s.begin();
    cout << cur << " ";
    s.erase(cur);
    for (int nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) s.insert(nxt);
    }
  }
}