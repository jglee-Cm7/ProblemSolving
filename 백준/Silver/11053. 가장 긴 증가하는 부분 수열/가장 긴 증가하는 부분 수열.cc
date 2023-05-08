#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n, 0);
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    int mx = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) mx = max(mx, dp[j]);
    }
    dp[i] = mx + 1;
  }

  cout << *max_element(dp.begin(), dp.end());
}