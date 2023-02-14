#include <bits/stdc++.h>
using namespace std;
long long dp[55];

long long getOnes(long long x) {
  long long ans = x & 1;
  for (int i = 54; i > 0; i--) {
    if (x & (1LL << i)) {
      ans += dp[i] + x - (1LL << i) + 1;
      x -= 1LL << i;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  dp[1] = 1;
  for (int i = 2; i < 55; i++)
    dp[i] = dp[i - 1] * 2LL + (1LL << (i - 1));
  cout << getOnes(b) - getOnes(a - 1);
}