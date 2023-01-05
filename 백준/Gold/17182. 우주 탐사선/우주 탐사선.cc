#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  k++;
  vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
  vector<int> planet;
  for (int i = 1; i <= n; i++) {
    if (i != k) planet.push_back(i);
    for (int j = 1; j <= n; j++) {
      cin >> cost[i][j];
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (cost[i][k] + cost[k][j] < cost[i][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++)
  //     cout << cost[i][j] << " ";
  //   cout << "\n";
  // }

  int ans = 20000;
  do {
    int s = k;
    int mn = 0;
    for (int v : planet) {
      mn += cost[s][v];
      s = v;
    }
    ans = min(ans, mn);
  } while (next_permutation(planet.begin(), planet.end()));
  cout << ans;
}