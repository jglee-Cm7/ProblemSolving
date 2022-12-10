#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> adj[n + 1];
    vector<int> deg(n + 1);
    vector<int> time(n + 1);
    vector<int> acc(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> time[i];
    while (k--) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      deg[y]++;
    }
    int w;
    cin >> w;

    deque<int> q;
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 0) {
        acc[i] = time[i];
        q.push_back(i);
      }
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (int nxt : adj[cur]) {
        deg[nxt]--;
        acc[nxt] = max(acc[nxt], acc[cur] + time[nxt]);
        if (deg[nxt] == 0) q.push_back(nxt);
      }
    }
    cout << acc[w] << "\n";
  }
}