#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int a = 0;
  int b = 0;
  int value = 0;
  bool op = true;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] != '+' && s[i] != '-') {
      value *= 10;
      value += s[i] - '0';
    } else {
      if (op)
        a += value;
      else
        b += value;
      if (op && s[i] == '-') op = !op;
      value = 0;
    }
  }
  if (op)
    a += value;
  else
    b += value;
  cout << a - b;
}