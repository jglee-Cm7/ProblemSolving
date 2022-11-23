#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, s;
  int arr[100005];
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int sum = arr[0];
  int mn = 0x7fffffff;
  int j = 1;
  for (int i = 0; i < n; i++) {
    while (j < n && sum < s) {
      sum += arr[j];
      j++;
    }
    if (sum >= s) {
      mn = min(mn, j - i);
      sum -= arr[i];
    } else
      break;
  }
  cout << (mn == 0x7fffffff ? 0 : mn);
}