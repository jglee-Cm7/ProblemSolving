#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, k;
  string w;
  cin >> t;
  while (t--) {
    cin >> w >> k;
    int mn = 0x7fffffff;
    int mx = 0;
    for (int i = 0; i < w.length(); i++) {
      char target = w[i];
      int cnt = 0;
      int nIdx = i;
      int st = i;
      int en = -1;
      while (nIdx != -1) {
        cnt++;
        if (cnt == k) {
          en = nIdx;
          break;
        }
        nIdx = w.find(target, nIdx + 1);
      }
      if (en == -1) continue;
      mn = min(mn, en - st + 1);
      mx = max(mx, en - st + 1);
    }
    if (mn == 0x7fffffff && mx == 0)
      cout << "-1\n";
    else
      cout << mn << " " << mx << "\n";
  }
}