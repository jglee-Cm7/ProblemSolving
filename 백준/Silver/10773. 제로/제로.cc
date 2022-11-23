#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int s[100005];
  int t = 0, k, v, sum = 0;

  cin >> k;
  while (k--) {
    cin >> v;
    if (v == 0) {
      if (t > 0) t--;
    } else {
      s[t] = v;
      t++;
    }
  }
  for (int i = 0; i < t; i++)
    sum += s[i];
  cout << sum;
}