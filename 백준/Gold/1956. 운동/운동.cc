#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int v, e;
  cin >> v >> e;

  vector<vector<int>> floyd(v + 1, vector<int>(v + 1, 0x3f3f3f3f));
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    floyd[a][b] = min(floyd[a][b], c);
  }
  for (int k = 1; k <= v; k++) {
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++)
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }
  }

  // for (int i = 1; i <= v; i++) {
  //   for (int j = 1; j <= v; j++)
  //     cout << floyd[i][j] << " ";
  //   cout << "\n";
  // }

  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= v; i++)
    ans = min(ans, floyd[i][i]);

  if (ans >= 0x3f3f3f3f)
    cout << "-1";
  else
    cout << ans;
}