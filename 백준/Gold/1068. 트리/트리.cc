#include <bits/stdc++.h>
using namespace std;

vector<int> adj[55];
vector<int> parent(55);
vector<bool> leaf(55, true);
int dfs(int cur) {
  int result = leaf[cur] ? 1 : 0;
  for (int nxt : adj[cur]) {
    if (nxt == parent[cur]) continue;
    result += dfs(nxt);
  }
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    parent[i] = p;
    if (p == -1) continue;
    adj[i].push_back(p);
    adj[p].push_back(i);
    leaf[p] = false;
  }
  cin >> d;
  int leafCnt = 0;
  for (int i = 0; i < n; i++)
    if (leaf[i]) leafCnt++;

  int ans = leafCnt - dfs(d);
  int dp = parent[d];
  if (dp != -1) {
    int dpp = parent[dp];
    int adjCnt = adj[dp].size();
    if (dpp != -1 && adjCnt == 2)
      ans++;
    else if (dpp == -1 && adjCnt == 1)
      ans++;
  }
  cout << ans;
}