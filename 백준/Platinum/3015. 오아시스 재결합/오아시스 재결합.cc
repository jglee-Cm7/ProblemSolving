#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<pair<int, int>> s;
  long long answer = 0;
  while (n--) {
    int h;
    cin >> h;
    int cnt = 1;
    while (!s.empty() && h >= s.top().first) {
      answer += s.top().second;
      if (s.top().first == h) {
        cnt += s.top().second;
      }
      s.pop();
    }
    if (!s.empty()) answer++;
    s.push({h, cnt});
  }
  cout << answer;
}