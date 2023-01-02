#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> coord(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    coord[i] = {x, y};
  }
  sort(coord.begin(), coord.end());
  for (auto [x, y] : coord) {
    cout << x << " " << y << "\n";
  }
}