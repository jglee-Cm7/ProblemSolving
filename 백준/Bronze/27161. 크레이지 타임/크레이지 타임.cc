#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int cur = 1;
  bool dir = true;
  while (n--) {
    string s;
    int t;
    cin >> s >> t;
    if (cur == t) {
      if (s == "HOURGLASS")
        cout << cur << " NO\n";
      else
        cout << cur << " YES\n";
    } else {
      cout << cur << " NO\n";
      if (s == "HOURGLASS") dir = !dir;
    }

    if (dir) {
      cur++;
      if (cur == 13) cur = 1;
    } else {
      cur--;
      if (cur == 0) cur = 12;
    }
  }
}