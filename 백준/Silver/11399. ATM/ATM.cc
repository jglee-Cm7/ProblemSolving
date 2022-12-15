#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &v : a)
    cin >> v;
  sort(a.begin(), a.end());
  int acc = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    acc += a[i];
    ans += acc;
  }
  cout << ans;
}