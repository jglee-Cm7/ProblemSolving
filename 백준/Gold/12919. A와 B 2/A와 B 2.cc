#include <bits/stdc++.h>
using namespace std;

int ans;

void func(string a, string b) {
  if (a.length() == b.length()) {
    if (a.compare(b) == 0) ans = 1;
    return;
  }

  if (ans) return;
  if (b[b.length() - 1] == 'A') {
    string tmp = b;
    tmp.pop_back();
    func(a, tmp);
  }

  if (ans) return;
  if (b[0] == 'B') {
    string tmp = b;
    reverse(tmp.begin(), tmp.end());
    tmp.pop_back();
    func(a, tmp);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;
  func(a, b);
  cout << ans;
}