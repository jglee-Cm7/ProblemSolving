#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  while (1) {
    t++;
    int n, m;
    cin >> n >> m;
    if (n == 0) break;
    vector<int> adj[505];
    vector<int> vis(505);
    deque<int> q;
    while (m--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int tCnt = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      bool check = true;
      vis[i] = 1;
      q.push_back(i);

      while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        for (auto nxt : adj[cur]) {
          if (vis[nxt] == vis[cur]) check = false;
          if (vis[nxt]) continue;
          vis[nxt] = vis[cur] + 1;
          q.push_back(nxt);
        }
      }
      if (check) tCnt++;
    }
    cout << "Case " << t << ": ";
    if (tCnt > 1)
      cout << "A forest of " << tCnt << " trees.\n";
    else if (tCnt == 1)
      cout << "There is one tree.\n";
    else
      cout << "No trees.\n";
  }
}