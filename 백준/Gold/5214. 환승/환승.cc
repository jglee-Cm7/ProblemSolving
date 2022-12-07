#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, m;
  cin >> n >> k >> m;
  vector<int> adj[m];
  vector<int> station[n + 1];
  vector<int> stHyper;
  vector<int> enHyper;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      station[s].push_back(i);
      if (s == 1) stHyper.push_back(i);
      if (s == n) enHyper.push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)station[i].size(); j++) {
      for (int k = j + 1; k < (int)station[i].size(); k++) {
        adj[station[i][j]].push_back(station[i][k]);
        adj[station[i][k]].push_back(station[i][j]);
      }
    }
  }

  int ans = 0x7fffffff;
  for (int st : stHyper) {
    deque<int> q;
    vector<int> vis(m);
    vis[st] = 1;
    q.push_back(st);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      if (find(enHyper.begin(), enHyper.end(), cur) != enHyper.end()) {
        ans = min(ans, vis[cur]);
        break;
      }
      for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = vis[cur] + 1;
        q.push_back(nxt);
      }
    }
  }
  cout << (ans == 0x7fffffff ? -1 : n == 1 ? ans : ans + 1);
}