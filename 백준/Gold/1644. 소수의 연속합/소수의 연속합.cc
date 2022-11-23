#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<bool> sieve(4000005, true);
  int n;
  vector<int> pn;
  cin >> n;
  for (int i = 2; i * i <= n; i++) {
    if (!sieve[i]) continue;
    for (int j = i * i; j <= n; j += i) {
      sieve[j] = false;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (sieve[i]) pn.push_back(i);
  }

  if (pn.empty()) {
    cout << 0;
    return 0;
  }

  int len = (int)pn.size();
  int ans = 0;
  int sum = pn[0];
  int j = 0;
  for (int i = 0; i < len; i++) {
    while (j < len && sum < n) {
      j++;
      if (j != len) sum += pn[j];
    }
    if (sum == n) ans++;
    sum -= pn[i];
  }

  cout << ans;
}