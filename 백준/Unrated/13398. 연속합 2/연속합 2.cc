#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<vector<int>> dp(2, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  dp[0][0] = arr[0];
  dp[1][0] = -1010;
  for (int i = 1; i < n; i++) {
    dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
    dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
  }
  int a = *max_element(dp[0].begin(), dp[0].end());
  int b = *max_element(dp[1].begin(), dp[1].end());

  cout << max(a, b);
}