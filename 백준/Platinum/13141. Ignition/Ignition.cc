#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> floyd(n + 1, vector<int>(n + 1, INF));
  vector<tuple<int, int, int>> edges;
  vector<int> burnTime(n + 1);
  for (int i = 1; i <= n; i++)
    floyd[i][i] = 0;
  while (m--) {
    int s, e, l;
    cin >> s >> e >> l;
    floyd[s][e] = min(floyd[s][e], l);
    floyd[e][s] = min(floyd[e][s], l);
    edges.push_back({s, e, l});
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }
  }

  double ans = INF;
  for (int i = 1; i <= n; i++) {
    double totalTime = 0;
    for (auto [s, e, l] : edges) {
      totalTime = max(totalTime, (double)(l + floyd[i][s] + floyd[i][e]) / 2);
    }
    ans = min(ans, totalTime);
  }
  cout << fixed;
  cout.precision(1);
  cout << ans;
}