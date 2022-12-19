#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> level(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
    auto it = s.lower_bound(x);
    int lv = 0;
    if (it == s.begin()) {
      if (next(it) == s.end())
        level[x] = 1;
      else
        level[x] = level[*next(it)] + 1;
    } else {
      lv = level[*prev(it)] + 1;
      if (next(it) != s.end()) lv = max(lv, level[*next(it)] + 1);
      level[x] = lv;
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (long long)level[i];
  }
  cout << ans;
}