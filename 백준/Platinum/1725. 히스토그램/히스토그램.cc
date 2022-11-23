#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<pair<long long, long long>> s;
  int n;
  long long answer = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    int idx = i;
    while (!s.empty() && s.top().first >= h) {
      answer = max(answer, (i - s.top().second) * s.top().first);
      idx = s.top().second;
      s.pop();
    }

    s.push({h, idx});
  }

  while (!s.empty()) {
    answer = max(answer, (n - s.top().second) * s.top().first);
    s.pop();
  }
  cout << answer << "\n";
}
