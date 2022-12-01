#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> score(n + 1);
  deque<int> q;

  while (1) {
    int a, b;
    cin >> a >> b;
    if (a == -1) break;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int mn = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    vector<int> vis(n + 1);
    vis[i] = 1;
    q.push_back(i);

    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();

      for (auto v : adj[cur]) {
        if (vis[v]) continue;
        vis[v] = vis[cur] + 1;
        score[i] = vis[v];
        q.push_back(v);
      }
    }
    mn = min(mn, score[i]);
  }

  cout << mn - 1 << " " << count(++score.begin(), score.end(), mn) << "\n";
  for (int i = 1; i <= n; i++) {
    if (mn == score[i]) cout << i << " ";
  }
}