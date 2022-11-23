#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string ip;
  string vp = "";
  stack<int> s1;  // 괄호
  vector<int> rz; // 레이저
  cin >> ip;

  for (int i = 0; i < (int)ip.length(); i++) {
    if (i + 1 < (int)ip.length() && ip[i] == '(' && ip[i + 1] == ')') {
      vp += '*';
      i++;
    } else
      vp += ip[i];
  }

  int ans = 0;
  for (int i = 0; i < (int)vp.length(); i++) {
    if (vp[i] == '*') {
      rz.push_back(i);
    } else if (vp[i] == '(') {
      // 첫 괄호이면 레이저 모두 초기화.
      if (s1.empty()) {
        rz.clear();
      }
      s1.push(i);
    } else {
      int cnt = 1;
      for (auto v : rz) {
        if (s1.top() < v) cnt++;
      }
      ans += cnt;
      s1.pop();
    }
  }
  cout << ans;
}