#include <bits/stdc++.h>
using namespace std;

vector<int> lc(10'005);
vector<int> rc(10'005);
vector<int> p(10'105);
vector<int> lv[10'005];

int mxLv;
int w;

void dfs(int cur, int l) {
  if (cur == 0) return;
  dfs(lc[cur], l + 1);
  lv[l].push_back(++w);
  dfs(rc[cur], l + 1);
  mxLv = max(mxLv, l);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    lc[v] = (l == -1 ? 0 : l);
    rc[v] = (r == -1 ? 0 : r);
    if (l != -1) p[l] = v;
    if (r != -1) p[r] = v;
  }
  int root = 0;
  for (int i = 1; i <= n; i++)
    if (p[i] == 0) {
      root = i;
      break;
    }
    
  dfs(root, 1);
  int ans = 0;
  int l = 0;
  for (int i = 1; i <= mxLv; i++) {
    int gap = *max_element(lv[i].begin(), lv[i].end()) -
              *min_element(lv[i].begin(), lv[i].end()) + 1;
    if (ans < gap) {
      l = i;
      ans = gap;
    }
  }
  cout << l << " " << ans;
}