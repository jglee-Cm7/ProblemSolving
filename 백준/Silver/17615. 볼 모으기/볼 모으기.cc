#include <bits/stdc++.h>
using namespace std;

int n;
string rb;
int func(char target) {
  int cnt = 0;
  int idx = 0;
  while (rb[idx] == target)
    idx++;
  while ((idx = rb.find(target, idx + 1)) != -1) {
    cnt++;
  }

  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> rb;
  int ans = min(func('R'), func('B'));
  reverse(rb.begin(), rb.end());
  ans = min(ans, func('R'));
  ans = min(ans, func('B'));
  cout << ans;
}