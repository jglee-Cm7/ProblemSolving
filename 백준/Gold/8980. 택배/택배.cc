#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c, m;
  cin >> n >> c >> m;
  vector<tuple<int, int, int>> order;
  vector<int> truck(n + 1);
  for (int i = 0; i < m; i++) {
    int st, en, w;
    cin >> st >> en >> w;
    order.push_back({en, st, w});
  }
  sort(order.begin(), order.end());
  int en, st, w;
  int ans = 0;
  for (auto q : order) {
    tie(en, st, w) = q;
    for (int i = st; i < en; i++)
      w = min(w, c - truck[i]);
    ans += w;
    for (int i = st; i < en; i++)
      truck[i] += w;
  }
  cout << ans;
}