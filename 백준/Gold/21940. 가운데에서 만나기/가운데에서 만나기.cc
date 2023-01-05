#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> floyd(n + 1, vector<int>(n + 1, 2000));
  while (m--) {
    int a, b, t;
    cin >> a >> b >> t;
    floyd[a][b] = t;
  }
  for (int i = 1; i <= n; i++)
    floyd[i][i] = 0;
  cin >> k;
  vector<int> stp(k);
  for (int i = 0; i < k; i++)
    cin >> stp[i];

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++)
  //     cout << floyd[i][j] << " ";
  //   cout << "\n";
  // }
  // cout << "\n";

  vector<pair<int, int>> rtp;
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int s : stp) {
      int rt = floyd[s][i] + floyd[i][s];
      // cout << s << " -> " << i << ": " << rt << "\n";
      mx = max(mx, rt);
    }
    rtp.push_back({mx, i});
  }
  // cout << "\n";

  sort(rtp.begin(), rtp.end());
  // for (auto [rt, p] : rtp)
  // cout << rt << " " << p << "\n";

  for (int i = 0; i < (int)rtp.size(); i++) {
    cout << rtp[i].second << " ";
    if (i + 1 < (int)rtp.size() && rtp[i].first != rtp[i + 1].first) break;
  }
}