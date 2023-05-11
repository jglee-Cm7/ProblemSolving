#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.length();
  vector<int> dp(n + 1, 0);

  if (s[0] == '0') {
    cout << 0;
    return 0;
  }
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    int pre = s[i - 2] - '0';
    int cur = s[i - 1] - '0';
    if (cur == 0 && (pre == 0 || pre > 2)) {
      cout << 0;
      return 0;
    }
    if (cur != 0) dp[i] = (dp[i] + dp[i - 1]) % 1000000;
    if (pre > 0 && (pre * 10 + cur) < 27) dp[i] = (dp[i] + dp[i - 2]) % 1000000;
  }

  cout << dp[n];
}