#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; i++)
      cin >> A[i];
    for (int i = 0; i < m; i++)
      cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    }
    cout << ans << "\n";
  }
}