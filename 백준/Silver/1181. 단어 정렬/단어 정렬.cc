#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<string> uniqueLowers;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    uniqueLowers.insert(s);
  }
  vector<string> lowers(uniqueLowers.begin(), uniqueLowers.end());

  sort(lowers.begin(), lowers.end(),
       [](const string &a, const string &b) -> bool {
         if (a.size() == b.size()) return a < b;
         return a.size() < b.size();
       });

  for (auto l : lowers)
    cout << l << "\n";
}