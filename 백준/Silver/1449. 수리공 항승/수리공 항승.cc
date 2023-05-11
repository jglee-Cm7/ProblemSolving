#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  l *= 10;
  vector<int> rep;
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    rep.push_back(r * 10);
  }
  sort(rep.begin(), rep.end());

  int ans = 1;
  int p = rep[0] - 5 + l;
  for (int r : rep) {
    if (r + 5 <= p) continue;
    if (r + 5 > p) {
      p = r - 5 + l;
      ans++;
    }
  }
  cout << ans;
}