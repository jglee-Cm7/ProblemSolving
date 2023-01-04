#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> liq;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    liq.push_back(l);
  }

  int sum = 2e9;
  int l1 = 0;
  int l2 = 0;
  for (int l : liq) {
    auto it = lower_bound(liq.begin(), liq.end(), -l);
    int target = 0, pre = 0, nxt = 0;
    if (it != liq.end() && *it != l) target = *it;
    if (it != liq.begin() && *prev(it) != l) pre = *prev(it);
    if (it != liq.end() && next(it) != liq.end() && *next(it) != l)
      nxt = *next(it);
    if (target) {
      int value = abs(l + target);
      if (value < sum) {
        l1 = l, l2 = target;
        sum = value;
      }
    }
    if (pre) {
      int value = abs(l + pre);
      if (value < sum) {
        l1 = l, l2 = pre;
        sum = value;
      }
    }
    if (nxt) {
      int value = abs(l + nxt);
      if (value < sum) {
        l1 = l, l2 = nxt;
        sum = value;
      }
    }
  }

  if (l1 > l2) swap(l1, l2);
  cout << l1 << " " << l2;
}