#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a;
  vector<int> answer;
  stack<int> s;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a.push_back(v);
  }
  reverse(a.begin(), a.end());
  for (auto v : a) {
    while (!s.empty() && s.top() <= v) {
      s.pop();
    }
    if (s.empty()) {
      answer.push_back(-1);
    } else {
      answer.push_back(s.top());
    }
    s.push(v);
  }
  reverse(answer.begin(), answer.end());
  for (auto v : answer)
    cout << v << " ";
}