#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> coin(n + 1, 0);
  vector<int> dp(k + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> coin[i];

  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = coin[i]; j <= k; j++) {
      dp[j] += dp[j - coin[i]];
    }
  }
  
  cout << dp[k];
}