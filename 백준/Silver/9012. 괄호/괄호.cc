#include <bits/stdc++.h>
using namespace std;
bool f(string &s) {
  bool result = false;
  stack<char> st;
  for (auto c : s) {
    if (c == '(') {
      st.push(c);
      continue;
    }
    if (st.empty()) return false;
    st.pop();
  }
  if (st.empty()) result = true;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (f(s))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}