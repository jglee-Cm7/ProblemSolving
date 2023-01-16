#include <bits/stdc++.h>
using namespace std;
int arr[25];
int ans = 0;
void func(int n, int s, int sum, int k) {
  if (n == k) {
    if (s == sum) ans++;
    return;
  }

  func(n, s, sum, k + 1);
  func(n, s, sum + arr[k], k + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int sum = 0;
  func(n, s, sum, 0);
  cout << (s == 0 ? ans - 1 : ans);
}