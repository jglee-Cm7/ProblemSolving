#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<tuple<int, int, int, string>> std(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    string s;
    cin >> s >> a >> b >> c;
    std[i] = {a, b, c, s};
  }
  sort(std.begin(), std.end(), [](const auto &a, const auto &b) -> bool {
    int a1, b1, c1, a2, b2, c2;
    string s1, s2;
    tie(a1, b1, c1, s1) = a;
    tie(a2, b2, c2, s2) = b;
    if (a1 != a2) return a1 > a2;
    if (b1 != b2) return b1 < b2;
    if (c1 != c2) return c1 > c2;
    return s1 < s2;
  });
  for (auto [a, b, c, s] : std) {
    cout << s << "\n";
  }
}