#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  vector<int> check(100005);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = 0, j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && check[arr[j]] < k) {
      check[arr[j]]++;
      j++;
    }
    ans = max(ans, j - i);
    check[arr[i]]--;
  }

  cout << ans;
}