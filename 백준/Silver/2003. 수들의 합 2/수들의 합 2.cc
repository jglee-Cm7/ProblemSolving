#include <bits/stdc++.h>
using namespace std;

int a[10005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  int sum = 0;
  int s = 0;
  int e = 0;
  while (1) {
    if (e == n && sum < m) break;
    if (e < n && sum < m) sum += a[e++];
    if (sum == m) {
      ans++;
      sum -= a[s++];
    }
    if (sum > m) sum -= a[s++];
  }

  cout << ans;
}