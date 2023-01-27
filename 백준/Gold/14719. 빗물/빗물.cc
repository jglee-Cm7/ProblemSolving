#include <bits/stdc++.h>
using namespace std;
int block[505][505];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, w;
  cin >> n >> w;
  vector<int> h(w);
  for (int &v : h)
    cin >> v;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (n - i <= h[j])
        block[i][j] = 1;
      else
        block[i][j] = 2;
    }
  }

  for (int i = 0; i < n; i++) {
    int idx = 0;
    while (idx < w) {
      for (; idx < w; idx++) {
        if (block[i][idx] == 1) break;
        block[i][idx] = 0;
      }
      idx++;
      int fIdx = -1;
      for (int j = idx; j < w; j++) {
        if (block[i][j] == 1) {
          fIdx = j;
          break;
        }
      }
      if (fIdx == -1) {
        for (; idx < w; idx++)
          block[i][idx] = 0;
      } else {
        while (block[i][fIdx] == 1)
          fIdx++;
        idx = fIdx - 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < w; j++) {
      if (block[i][j] == 2) ans++;
    }
  }
  cout << ans;
}