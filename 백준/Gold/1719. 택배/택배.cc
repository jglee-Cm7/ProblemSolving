#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> fl(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
  vector<vector<int>> nxt(n + 1, vector<int>(n + 1, 0));
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    fl[a][b] = w;
    fl[b][a] = w;
    nxt[a][b] = b;
    nxt[b][a] = a;
  }
  for (int i = 1; i <= n; i++)
    fl[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (fl[i][k] + fl[k][j] < fl[i][j]) {
          fl[i][j] = fl[i][k] + fl[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        cout << "- ";
      else
        cout << nxt[i][j] << " ";
    }
    cout << "\n";
  }
}