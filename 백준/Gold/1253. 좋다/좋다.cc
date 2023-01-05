#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int target = arr[i] - arr[j];
      int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
      while (idx == i || idx == j)
        idx++;
      if (idx >= n) continue;
      if (arr[j] + arr[idx] != arr[i]) continue;
      // cout << arr[i] << ": " << arr[j] << " + " << arr[idx] << "\n";
      ans++;
      break;
    }
  }
  cout << ans;
}