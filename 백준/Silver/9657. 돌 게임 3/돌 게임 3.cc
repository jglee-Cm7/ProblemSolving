#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(n + 1, -1);
  dp[1] = 0, dp[2] = 1, dp[3] = 0, dp[4] = 0;
  for (int i = 5; i < n + 1; i++) {
    if (dp[i - 1] || dp[i - 3] || dp[i - 4])
      dp[i] = 0;
    else
      dp[i] = 1;
  }
  cout << (dp[n] == 0 ? "SK" : "CY");
}