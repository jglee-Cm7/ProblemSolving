#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<long long> liq(n);
  for (int i = 0; i < n; i++)
    cin >> liq[i];

  sort(liq.begin(), liq.end());
  
  long long ans = 0xffffffff;
  vector<long long> ansLiq(3);
  for (int i = 0; i < n; i++) {
    long long a = liq[i];
    for (int j = i + 1; j < n; j++) {
      long long b = liq[j];
      int idx = lower_bound(liq.begin(), liq.end(), -(a + b)) - liq.begin();
      if (idx - 1 >= 0 && idx - 1 < n && idx - 1 != i && idx - 1 != j) {
        long long total = abs(a + b + liq[idx - 1]);
        if (total < ans) {
          ans = total;
          ansLiq[0] = a, ansLiq[1] = b, ansLiq[2] = liq[idx - 1];
        }
      }
      if (idx < n && idx != i && idx != j) {
        long long total = abs(a + b + liq[idx]);
        if (total < ans) {
          ans = total;
          ansLiq[0] = a, ansLiq[1] = b, ansLiq[2] = liq[idx];
        }
      }
      if (idx + 1 < n && idx + 1 != i && idx + 1 != j) {
        long long total = abs(a + b + liq[idx + 1]);
        if (total < ans) {
          ans = total;
          ansLiq[0] = a, ansLiq[1] = b, ansLiq[2] = liq[idx + 1];
        }
      }
    }
  }
  sort(ansLiq.begin(), ansLiq.end());
  for (int l : ansLiq)
    cout << l << " ";
}