#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> mt;
  for (int i = 0; i < n; i++) {
    int st, en;
    cin >> st >> en;
    mt.push_back({en, st});
  }
  sort(mt.begin(), mt.end());
  int t = 0;
  int ans = 0;
  for (auto [en, st] : mt) {
    if (t <= st) {
      t = en;
      ans++;
    }
  }
  cout << ans;
}