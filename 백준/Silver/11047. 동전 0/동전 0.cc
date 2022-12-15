#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> coins(n);
  for (int &coin : coins)
    cin >> coin;

  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += k / coins[i];
    k = k % coins[i];
    if (k == 0) break;
  }
  cout << ans;
}