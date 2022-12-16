#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  vector<char> compact;

  for (int i = 0; i < (int)s.size(); i++) {
    if (compact.empty())
      compact.push_back(s[i]);
    else {
      if (compact[compact.size() - 1] != s[i]) compact.push_back(s[i]);
    }
  }
  int zero = count(compact.begin(), compact.end(), '0');
  cout << min(zero, (int)compact.size() - zero);
}