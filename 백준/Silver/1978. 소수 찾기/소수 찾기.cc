#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
  if (num == 1) return 0;

  for (int i = 2; i < num; i++) {
    if (num % i == 0) return 0;
  }

  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &a : arr)
    cin >> a;

  int ans = 0;
  for (int a : arr) {
    if (isPrime(a)) ans++;
  }

  cout << ans;
}