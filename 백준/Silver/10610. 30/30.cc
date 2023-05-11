#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  sort(s.begin(), s.end(), greater<>());
  int valid = 0;
  int zero = 0;
  for (char c : s) {
    int v = c - '0';
    valid += v;
    if (v == 0) zero++;
  }
  if (valid % 3 || zero == 0)
    cout << -1;
  else {
    for (char c : s)
      cout << c;
  }
}