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
    vector<pair<int, int>> emp;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      emp.push_back({a, b});
    }

    sort(emp.begin(), emp.end());

    int cnt = 0;
    int mn = 0x7fffffff;
    for (auto [a, b] : emp) {
      if (b > mn)
        cnt++;
      else
        mn = b;
    }
    cout << n - cnt << "\n";
  }
}