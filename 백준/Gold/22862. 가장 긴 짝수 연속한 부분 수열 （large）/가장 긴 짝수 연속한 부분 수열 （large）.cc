#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int mx = 0;
  int len = 0;
  int dCnt = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n) {
      if (arr[j] % 2 && dCnt == k) break;
      if (arr[j] % 2) {
        dCnt++;
      }
      j++;
    }
    len = j - i - dCnt;
    mx = max(mx, len);
    if (arr[i] % 2 && dCnt) dCnt--;
  }

  cout << mx;
}