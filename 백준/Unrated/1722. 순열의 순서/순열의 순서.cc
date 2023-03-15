#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<ll> dp(n);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i < n; i++)
    dp[i] = dp[i - 1] * (ll)i;
  reverse(dp.begin(), dp.end());

  vector<bool> isUsed(n + 1, 0);
  if (t == 1) {
    ll k;
    cin >> k;
    k--;
    for (int i = 0; i < n; i++) {
      int cnt = k / dp[i];
      for (int j = 1; j <= n; j++) {
        if (isUsed[j]) continue;
        if (cnt) {
          cnt--;
          continue;
        }
        isUsed[j] = 1;
        cout << j << " ";
        break;
      }
      k %= dp[i];
    }
  } else {
    ll k = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int cnt = 0;
      for (int j = 1; j < x; j++) {
        if (isUsed[j]) continue;
        cnt++;
      }
      isUsed[x] = 1;
      k += (ll)cnt * (ll)dp[i];
    }
    cout << k + 1;
  }
}