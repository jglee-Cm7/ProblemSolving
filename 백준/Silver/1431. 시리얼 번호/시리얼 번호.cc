#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> serial(n);
  for (int i = 0; i < n; i++)
    cin >> serial[i];

  sort(serial.begin(), serial.end(),
       [](const string &a, const string &b) -> bool {
         if (a.size() < b.size()) return true;
         if (a.size() > b.size()) return false;
         int asum = 0;
         int bsum = 0;
         for (auto c : a) {
           if (c < 'A') asum += static_cast<int>(c) - '0';
         }
         for (auto c : b) {
           if (c < 'A') bsum += static_cast<int>(c) - '0';
         }
         if (asum < bsum) return true;
         if (asum > bsum) return false;
         if (asum == bsum) return a < b;
       });
  for (auto s : serial)
    cout << s << "\n";
}