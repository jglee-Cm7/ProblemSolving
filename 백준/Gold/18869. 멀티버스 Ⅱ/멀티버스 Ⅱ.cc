#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> uv(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int w;
      cin >> w;
      uv[i].push_back({w, j});
    }
    sort(uv[i].begin(), uv[i].end());
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool isSame = 1;
      for (int k = 0; k < m; k++) {
        if (uv[i][k].second != uv[j][k].second) {
          isSame = 0;
          break;
        } else {
          if (i != n - 1 && (uv[i][k].first < uv[i][k + 1].first) !=
                                (uv[j][k].first < uv[j][k + 1].first)) {
            isSame = 0;
            break;
          }
        }
      }
      if (isSame) ans++;
    }
  }
  cout << ans;
}