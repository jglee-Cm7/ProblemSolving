#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n;
  cin >> n;

  int answer = 1;
  for (long long i = 2; i < n; i++) {
    long long s = i * (i + 1) / 2;
    if (s > n) {
      answer = i - 1;
      break;
    }
    if (s == n) {
      answer = i;
      break;
    }
  }

  cout << answer;
}