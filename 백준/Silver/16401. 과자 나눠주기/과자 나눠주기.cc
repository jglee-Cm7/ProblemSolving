#include <bits/stdc++.h>
using namespace std;
int getCookieCount(vector<int> &cookie, int len) {
  int count = 0;
  for (int c : cookie)
    count += c / len;
  return count;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;
  vector<int> cookie(n);
  for (int i = 0; i < n; i++)
    cin >> cookie[i];

  int st = 1;
  int en = 1'000'000'000;
  while (st <= en) {
    int mid = (st + en) / 2;
    int count = getCookieCount(cookie, mid);
    if (count >= m)
      st = mid + 1;
    else
      en = mid - 1;
  }
  cout << en;
}