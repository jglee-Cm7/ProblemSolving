#include <bits/stdc++.h>
using namespace std;

int check[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int arr[100005];

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  long long ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && check[arr[j]] == 0) {
      check[arr[j]] = 1;
      j++;
    }
    ans += j - i;
    check[arr[i]] = 0;
  }
  cout << ans;
}