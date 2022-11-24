#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, d, k, c;
  cin >> n >> d >> k >> c;

  vector<int> arr(n + k);
  vector<int> check(d + 1);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = n; i < n + k - 1; i++)
    arr[i] = arr[i - n];

  int j = 0;
  int cnt = 0;
  int len = 0;
  int mx = 0;
  for (int i = 0; i < n + k - 1; i++) {
    while (j < n + k - 1 && cnt < k) {
      if (check[arr[j]] == 0) len++;
      check[arr[j]]++;
      cnt++;
      j++;
    }

    mx = max(mx, check[c] == 0 ? len + 1 : len);
    check[arr[i]]--;
    if (check[arr[i]] == 0) len--;
    cnt--;
  }

  cout << mx;
}