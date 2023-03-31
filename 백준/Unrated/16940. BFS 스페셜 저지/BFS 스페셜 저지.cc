#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100010];
int order[100010];
int priority[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    order[i] = a;
    priority[a] = i;
  }
  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end(),
         [](const auto &a, const auto &b) -> bool {
           return priority[a] < priority[b];
         });
  }

  vector<int> vis(n + 1, 0);
  queue<int> q;
  vis[1] = 1;
  q.push(1);
  int i = 1;

  int ans = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur != order[i++]) {
      ans = 0;
      break;
    }
    for (int x : adj[cur]) {
      if (vis[x]) continue;
      vis[x] = vis[cur] + 1;
      q.push(x);
    }
  }
  cout << ans;
}