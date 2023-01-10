#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<ll>> arr(4, vector<ll>(n, 0));
  vector<int> cd;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++)
      cin >> arr[j][i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cd.push_back(arr[2][i] + arr[3][j]);
  }
  for (int i = 0; i < 2; i++)
    sort(arr[i].begin(), arr[i].end());
  sort(cd.begin(), cd.end());

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll target = -(arr[0][i] + arr[1][j]);
      ans += upper_bound(cd.begin(), cd.end(), target) -
             lower_bound(cd.begin(), cd.end(), target);
    }
  }
  cout << ans;
}