#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> vis(100005);
vector<int> vNum(100005);
int dfs(int cur) {
  if (vis[cur]) return 0;
  vis[cur] = 1;
  int cnt = 1;
  for (int nxt : adj[cur]) {
    vNum[nxt] = dfs(nxt);
    cnt += vNum[nxt];
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r, q;
  cin >> n >> r >> q;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vNum[r] = dfs(r);

  while (q--) {
    int v;
    cin >> v;
    cout << vNum[v] << "\n";
  }
}