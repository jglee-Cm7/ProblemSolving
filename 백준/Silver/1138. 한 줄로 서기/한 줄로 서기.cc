#include <bits/stdc++.h>
using namespace std;
int arr[15];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, left;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> left;
    for (int j = 0; j < n; j++) {
      if (left == 0 && arr[j] == 0) {
        arr[j] = i;
        break;
      } else if (arr[j] == 0)
        left--;
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}