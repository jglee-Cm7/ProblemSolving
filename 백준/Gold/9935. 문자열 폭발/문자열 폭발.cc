#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str, bm;
  cin >> str >> bm;
  int n = str.length();
  int m = bm.length();

  vector<char> ans;
  for (int i = 0; i < n; i++) {
    ans.push_back(str[i]);
    int l = ans.size();
    if (l >= m) {
      bool boom = 1;
      for (int j = 0; j < m; j++) {
        if (bm[j] != ans[l - m + j]) {
          boom = 0;
          break;
        }
      }
      if (boom) ans.erase(ans.begin() + l - m, ans.end());
    }
  }
  if (ans.size() == 0)
    cout << "FRULA";
  else {
    for (char c : ans)
      cout << c;
  }
}