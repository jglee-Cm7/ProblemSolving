#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int &v : a) cin >> v;
  for (int &v : b) cin >> v;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i] * b[i];
  cout << ans;
}