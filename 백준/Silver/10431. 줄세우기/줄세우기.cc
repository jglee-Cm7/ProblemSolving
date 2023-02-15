#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr;
    int ans = 0;
    for (int i = 0; i < 20; i++) {
      sort(arr.begin(), arr.end());
      int v;
      cin >> v;
      int pos = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
      int cnt = arr.size() - pos;
      ans += cnt;
      arr.push_back(v);
    }
    cout << n << " " << ans << "\n";
  }
}