#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  bool isTag = false;
  char c;
  string w;
  string ans = "";
  while (cin.get(c)) {
    if (c == '<') {
      if (!w.empty()) {
        reverse(w.begin(), w.end());
        ans += w;
        w.clear();
      }
      isTag = true;
    }
    if (!isTag && c != ' ') w.push_back(c);
    if (isTag) ans += c;
    if (c == '>') isTag = false;

    if (c == ' ') {
      if (!w.empty()) {
        reverse(w.begin(), w.end());
        ans += w + " ";
        w.clear();
      }
    }
  }
  if (!w.empty()) {
    reverse(w.begin(), w.end());
    ans += w;
  }

  for (char c : ans) {
    if (c != '\n') cout << c;
  }
}