#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> poly;
  poly.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    poly.push_back({x, y});
  }
  sort(poly.begin(), poly.end());
  int answer = 0;
  int h = 0;
  int sx = 0;
  for (int i = 0; i < (int)poly.size(); i++) {
    auto [x, y] = poly[i];
    if (y >= h) {
      answer += (x - sx) * h;
      sx = x;
      h = y;
    }
  }
  answer += h;
  h = 0, sx = 1010;
  for (int i = (int)poly.size() - 1; i >= 0; i--) {
    auto [x, y] = poly[i];
    if (y > h) {
      answer += (sx - x) * h;
      sx = x;
      h = y;
    }
  }
  cout << answer;
}