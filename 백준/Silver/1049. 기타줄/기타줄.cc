#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int mnP = INT_MAX;
  int mnS = INT_MAX;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    mnP = min(mnP, a);
    mnS = min(mnS, b);
  }
  int ans = 0;
  if (mnS * 6 < mnP)
    ans = mnS * n;
  else
    ans = min((n / 6) * mnP + (n % 6) * mnS, ((n / 6) + 1) * mnP);
  cout << ans;
}