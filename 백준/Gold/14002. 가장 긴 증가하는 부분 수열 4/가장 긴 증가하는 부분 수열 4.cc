#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n, 0);
  vector<int> dp(n, 0);
  vector<int> prev(n, -1);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    int mx = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp[j] > mx) {
        mx = dp[j];
        prev[i] = j;
      }
    }
    dp[i] = mx + 1;
  }
  int mx = 0;
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] > mx) {
      mx = dp[i];
      idx = i;
    }
  }

  cout << mx << "\n";
  vector<int> lis;
  while (idx != -1) {
    lis.push_back(arr[idx]);
    idx = prev[idx];
  }

  for (auto i = lis.rbegin(); i != lis.rend(); i++)
    cout << *i << " ";
}