#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<string, int> list;
  for (int i = 0; i < n + m; i++) {
    string s;
    cin >> s;
    list[s]++;
  }
  vector<string> ans;
  for (auto [key, value] : list)
    if (value > 1) ans.push_back(key);

  cout << ans.size() << "\n";
  for (string a : ans)
    cout << a << "\n";
}

// 해시