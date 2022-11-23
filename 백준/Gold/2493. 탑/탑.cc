#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<pair<int, int>> s;
  s.push(make_pair(0, 100000000));

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    while (s.top().second < v) {
      s.pop();
    }
    cout << s.top().first << " ";
    s.push(make_pair(i + 1, v));
  }
}