#include <bits/stdc++.h>
using namespace std;
bool f(string &s) {
  stack<char> st;

  for (auto c : s) {
    if (!st.empty() && st.top() == c) {
      st.pop();
      continue;
    }

    st.push(c);
  }

  return st.empty();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int ans = 0;
  while (t--) {
    string s;
    cin >> s;
    if (f(s)) ans++;
  }
  cout << ans;
}