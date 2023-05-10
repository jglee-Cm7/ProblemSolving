#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int answer = 0;
  while (n > 0) {
    if (n % 5 == 0) {
      answer += n / 5;
      n = 0;
      break;
    }
    n -= 3;
    answer++;
  }

  if (n == 0)
    cout << answer;
  else
    cout << -1;
}