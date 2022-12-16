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
    vector<int> prices(n);
    for (int &p : prices)
      cin >> p;

    int mxPrice = 0;
    long long balance = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (prices[i] > mxPrice) {
        mxPrice = prices[i];
      } else {
        balance += (long long)(mxPrice - prices[i]);
      }
    }
    cout << balance << "\n";
  }
}