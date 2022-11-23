#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  vector<int> a;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a.push_back(v);
  }

  sort(a.begin(), a.end());

  int mn = 0x7fffffff;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && a[j] - a[i] < m)
      j++;
    if (j == n) break;
    mn = min(mn, a[j] - a[i]);
  }
  cout << mn;
}