#include <bits/stdc++.h>
using namespace std;

int n, m, l, k;
vector<pair<int, int>> star(105);

int getBounce(int x, int y) {
  int c = 0;
  for (int i = 0; i < k; i++) {
    auto [a, b] = star[i];
    if (a < x || a > x + l || b < y || b > y + l) continue;
    c++;
  }
  return c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> l >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    star[i] = {x, y};
  }

  int mx = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      mx = max(mx, getBounce(star[i].first, star[j].second));
    }
  }
  cout << k - mx;
}
