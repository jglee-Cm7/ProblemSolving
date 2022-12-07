#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, tn;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<int> vis(n + 1);
  vector<bool> f(n + 1, false);
  vector<int> p[m];
  cin >> tn;
  vector<int> t(tn);
  for (int i = 0; i < tn; i++) {
    cin >> t[i];
  }

  for (int i = 0; i < m; i++) {
    int pn;
    cin >> pn;
    for (int j = 0; j < pn; j++) {
      int tmp;
      cin >> tmp;
      p[i].push_back(tmp);
    }
    for (int x = 0; x < pn; x++) {
      for (int y = x + 1; y < pn; y++) {
        adj[p[i][x]].push_back(p[i][y]);
        adj[p[i][y]].push_back(p[i][x]);
      }
    }
  }

  deque<int> q;

  for (int i = 0; i < tn; i++) {
    vis[t[i]] = 1;
    q.push_back(t[i]);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      f[cur] = true;

      for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        q.push_back(nxt);
        vis[nxt] = 1;
      }
    }
  }
  int ans = 0;
  for (auto pp : p) {
    bool check = true;
    for (auto ppp : pp) {
      if (f[ppp]) {
        check = false;
        break;
      }
    }
    if (check) ans++;
  }

  cout << ans;
}