#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> lc(n + 1);
  vector<int> rc(n + 1);
  vector<int> p(n + 1);
  vector<int> vis(n + 1);
  int ans = 0;

  for (int i = 0; i < n; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    lc[v] = (l == -1 ? 0 : l);
    rc[v] = (r == -1 ? 0 : r);
    if (l != -1) p[l] = v;
    if (r != -1) p[r] = v;
  }
  int en = rc[1] != 0 ? rc[1] : 1;
  while (1) {
    int nxt = rc[en] != 0 ? rc[en] : en;
    if (nxt == en) break;
    en = nxt;
  }
  int cur = 1;
  while (1) {
    vis[cur] = 1;
    int left = lc[cur];
    int right = rc[cur];
    int parent = p[cur];
    if (left && !vis[left]) {
      ans++;
      cur = left;
    } else if (right && !vis[right]) {
      ans++;
      cur = right;
    } else if (cur == en)
      break;
    else if (parent) {
      ans++;
      cur = parent;
    }
  }
  cout << ans;
}