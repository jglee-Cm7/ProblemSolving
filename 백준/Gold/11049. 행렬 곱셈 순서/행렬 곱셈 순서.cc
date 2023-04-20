#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> d(n + 1);
  vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++)
    cin >> d[i] >> d[i + 1];

  for (int j = 1; j <= n; j++) {
    for (int i = j - 1; i > 0; i--) {
      int mn = INT_MAX;
      for (int k = i; k < j; k++)
        mn = min(mn, m[i][k] + m[k + 1][j] + (d[i - 1] * d[k] * d[j]));
      m[i][j] = mn;
    }
  }

  cout << m[1][n];
}