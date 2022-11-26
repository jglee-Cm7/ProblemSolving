#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> classes(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> classes[i][j];
    }
    sort(classes[i].begin(), classes[i].end());
  }

  vector<pair<int, int>> pts(n);

  for (int i = 0; i < n; i++) {
    pts[i] = {0, classes[i][0]};
  }

  int ans = 0x7fffffff;
  int st = 0;
  while (1) {
    int mnIdx = 0;
    int mn = 0x7fffffff, mx = 0;
    for (int i = 0; i < n; i++) {
      if (pts[i].second < mn) {
        mn = pts[i].second;
        st = pts[i].first;
        mnIdx = i;
      }
      if (pts[i].second > mx) {
        mx = pts[i].second;
      }
    }
    ans = min(ans, mx - mn);
    if (ans == 0 || st == m - 1) break;
    pts[mnIdx] = {st + 1, classes[mnIdx][st + 1]};
  }
  cout << ans;
}
