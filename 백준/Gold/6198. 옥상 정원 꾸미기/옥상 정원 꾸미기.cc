#include <bits/stdc++.h>

using namespace std;

// O(n)
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int bd[80005];
  long long answer = 0;
  stack<int> s;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> bd[i];
  for (int i = 0; i < n; i++) {
    if (s.empty())
      s.push(bd[i]);
    else {
      while (!s.empty() && s.top() <= bd[i]) {
        s.pop();
      }
      answer += (long long)s.size();
      s.push(bd[i]);
    }
  }

  cout << answer;
}
