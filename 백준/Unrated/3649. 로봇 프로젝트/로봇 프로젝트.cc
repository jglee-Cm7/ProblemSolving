#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, n;
  while (cin >> x) {
    cin >> n;
    x *= 10'000'000;
    vector<int> lego(n);
    for (int i = 0; i < n; i++)
      cin >> lego[i];
    sort(lego.begin(), lego.end());
    int l1, l2;
    int gap = -1;
    for (int i = 0; i < (int)lego.size(); i++) {
      int l = lego[i];
      if (!binary_search(lego.begin() + i + 1, lego.end(), x - l)) continue;
      int a = min(l, x - l);
      int b = x - a;
      int d = abs(a - b);
      if (d > gap) {
        gap = d, l1 = a, l2 = b;
      }
    }
    if (gap == -1)
      cout << "danger\n";
    else
      cout << "yes " << l1 << " " << l2 << "\n";
  }
}