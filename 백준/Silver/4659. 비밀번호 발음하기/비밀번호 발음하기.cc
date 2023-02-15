#include <bits/stdc++.h>
using namespace std;
char aeiou[5] = {'a', 'e', 'i', 'o', 'u'};
bool check(string s) {
  bool one = 0;
  bool two = 1;
  bool three = 1;
  for (char c : s) {
    bool flag = 0;
    for (int i = 0; i < 5; i++) {
      if (aeiou[i] == c) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      one = 1;
      break;
    }
  }

  if (!one) return 0;

  stack<int> st; // 0: 모음, 1: 자음
  for (char c : s) {
    bool flag = 0;
    for (int i = 0; i < 5; i++) {
      if (aeiou[i] == c) {
        flag = 1;
        break;
      }
    }
    // 모음
    if (flag) {
      if (!st.empty() && st.top() == 1) {
        while (!st.empty())
          st.pop();
      }
      st.push(0);
    } else {
      if (!st.empty() && st.top() == 0) {
        while (!st.empty())
          st.pop();
      }
      st.push(1);
    }

    if (st.size() == 3) {
      two = 0;
      break;
    }
  }

  if (!two) return 0;
  int cnt = 1;
  char prv = 0;
  for (char c : s) {
    if (c == 'e' || c == 'o') {
      cnt = 1;
      prv = c;
      continue;
    }

    if (prv == c)
      cnt++;
    else
      cnt = 1;
    prv = c;

    if (cnt == 2) {
      three = 0;
      break;
    }
  }

  if (!three) return 0;

  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  while (1) {
    cin >> s;
    if (s == "end") break;
    cout << "<" << s << "> is ";
    if (!check(s)) cout << "not ";
    cout << "acceptable.\n";
  }
}