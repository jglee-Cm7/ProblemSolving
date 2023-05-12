#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, j;
  cin >> n >> m;
  vector<int> sc(n + 1, 0);
  for (int i = 1; i <= m; i++)
    sc[i] = 1;

  cin >> j;
  int ans = 0;
  while (j--) {
    int k;
    cin >> k;
    if (sc[k]) continue;
    int gap = 0;
    bool dir = 0;
    // 왼쪽 탐색
    for (int i = k; i >= 0; i--) {
      if (sc[i]) {
        gap = k - i;
        dir = 1;
        break;
      }
    }
    if (gap == 0) {
      // 오른쪽 탐색
      for (int i = k; i <= n; i++) {
        if (sc[i]) {
          gap = i - k;
          break;
        }
      }
    }
    if (dir) {
      for (int i = 1; i <= k - m; i++)
        sc[i] = 0;
      for (int i = k - m + 1; i <= k; i++)
        sc[i] = 1;
      for (int i = k + 1; i <= n; i++)
        sc[i] = 0;
    } else {
      for (int i = 1; i < k; i++)
        sc[i] = 0;
      for (int i = k; i < k + m; i++)
        sc[i] = 1;
      for (int i = k + m; i <= n; i++)
        sc[i] = 0;
    }

    ans += gap;
  }

  cout << ans;
}