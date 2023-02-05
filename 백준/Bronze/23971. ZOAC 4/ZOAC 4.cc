#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, h, w;
  cin >> n >> m >> h >> w;
  int x = 0;
  int y = 0;
  for (int i = 0; i < m; i += w + 1)
    x++;
  for (int i = 0; i < n; i += h + 1)
    y++;
  cout << x * y;
}