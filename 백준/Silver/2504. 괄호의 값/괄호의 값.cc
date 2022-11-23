#include <bits/stdc++.h>
using namespace std;

bool vp(string &s) {
  stack<char> st;
  for (auto c : s) {
    if (c == ')') {
      if (st.empty() || st.top() == '[') return false;
      st.pop();
    } else if (c == ']') {
      if (st.empty() || st.top() == '(') return false;
      st.pop();
    } else {
      st.push(c);
    }
  }
  return st.empty();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<string> st;
  string s;
  cin >> s;

  if (!vp(s)) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == '(') {
      st.push("(");
    } else if (s[i] == '[') {
      st.push("[");
    } else if (s[i] == ')') {
      if (s[i - 1] == '(') {
        st.pop();
        st.push("2");
      } else {
        int tmp = 0;
        while (st.top() != "(") {
          tmp += stoi(st.top());
          st.pop();
        }
        tmp *= 2;
        st.pop();
        st.push(to_string(tmp));
      }
    } else if (s[i] == ']') {
      if (s[i - 1] == '[') {
        st.pop();
        st.push("3");
      } else {
        int tmp = 0;
        while (st.top() != "[") {
          tmp += stoi(st.top());
          st.pop();
        }
        tmp *= 3;
        st.pop();
        st.push(to_string(tmp));
      }
    }
  }
  int ans = 0;
  while (!st.empty()) {
    ans += stoi(st.top());
    st.pop();
  }
  cout << ans;
}
