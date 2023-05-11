#include <bits/stdc++.h>
using namespace std;
int alpha[26];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (char c : s)
    alpha[c - 'A']++;

  string ans;
  if (s.length() % 2 == 0) {
    // 모든 알파벳이 짝수개여야함.
    for (int i = 0; i < 26; i++) {
      if (alpha[i] % 2) {
        cout << "I'm Sorry Hansoo";
        return 0;
      }
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < alpha[i] / 2; j++)
        ans.push_back('A' + i);
    }
    for (int i = 25; i >= 0; i--) {
      for (int j = 0; j < alpha[i] / 2; j++)
        ans.push_back('A' + i);
    }
  } else {
    int odd = 0;
    char center = 0;
    for (int i = 0; i < 26; i++) {
      if (alpha[i] % 2) {
        odd++;
        center = i;
      }
    }
    if (odd > 1) {
      cout << "I'm Sorry Hansoo";
      return 0;
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < alpha[i] / 2; j++)
        ans.push_back('A' + i);
    }
    ans.push_back('A' + center);
    for (int i = 25; i >= 0; i--) {
      for (int j = 0; j < alpha[i] / 2; j++)
        ans.push_back('A' + i);
    }
  }

  cout << ans;
}