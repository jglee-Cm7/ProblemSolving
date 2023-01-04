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

  sort(liq.begin(), liq.end());

  int st = 0;
  int en = n - 1;
  int mn = 2e9;
  while (st != en) {
    int sum = liq[st] + liq[en];
    if (abs(mn) > abs(sum)) mn = sum;
    if (sum > 0)
      en--;
    else if (sum < 0)
      st++;
    else
      break;
  }
  cout << mn;
}