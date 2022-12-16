#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> lv(n);
  for (int &p : lv)
    cin >> p;

  int ans = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (lv[i] < lv[i + 1]) continue;
    ans += lv[i] - (lv[i + 1] - 1);
    lv[i] = lv[i + 1] - 1;
  }
  cout << ans;
}