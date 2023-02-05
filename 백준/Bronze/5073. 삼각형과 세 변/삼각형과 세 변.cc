#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  while (1) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) break;
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (a + b <= c)
      cout << "Invalid\n";
    else {
      if (a == b && b == c && a == c)
        cout << "Equilateral\n";
      else if (a != b && b != c && a != c)
        cout << "Scalene\n";
      else
        cout << "Isosceles\n";
    }
  }
}