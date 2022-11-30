#include <bits/stdc++.h>
using namespace std;

int n;
int h[605];
bool check[605];

int makeSnow(int ans, int s1) {
  int mn = ans;
  int s2 = 0;

  // for (int i = 0; i < n; i++)
  //   cout << check[i] << " ";
  // cout << "ans: " << ans << " | s1: " << s1 << "\n";

  int y = n - 1;
  for (int x = 0; x < n; x++) {
    if (mn == 0) break;
    if (x == y) break;
    if (check[x]) continue;
    while (check[y])
      y--;
    // cout << x << " " << y << "\n";
    s2 = h[x] + h[y];
    mn = min(mn, abs(s2 - s1));
    while (s1 < s2) {
      y--;
      if (x == y) {
        return mn;
        cout << s1 << "\n";
      }
      if (check[y]) continue;
      s2 = h[x] + h[y];
      mn = min(mn, abs(s2 - s1));
    }
  }

  return mn;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> h[i];

  sort(h, h + n);

  int s1 = 0;
  int ans = 0x7fffffff;
  for (int i = 0; i < n; i++) {
    check[i] = 1;
    for (int j = i + 1; j < n; j++) {
      check[j] = 1;
      s1 = h[i] + h[j];
      ans = makeSnow(ans, s1);
      if (ans == 0) {
        cout << ans;
        return 0;
      }
      check[j] = 0;
    }
    check[i] = 0;
  }

  cout << ans;
}
