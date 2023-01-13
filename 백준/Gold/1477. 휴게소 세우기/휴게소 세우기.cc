#include <bits/stdc++.h>
using namespace std;
int getRest(vector<int> &rest, int l, int d) {
  int count = 0;
  for (int i = 1; i < (int)rest.size(); i++) {
    if (rest[i] - rest[i - 1] <= d) continue;
    int r = rest[i - 1];
    while (rest[i] - r > d) {
      count++;
      r += d;
    }
  }
  return count;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, l;
  cin >> n >> m >> l;
  vector<int> rest;
  rest.push_back(0);
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    rest.push_back(r);
  }
  rest.push_back(l);
  sort(rest.begin(), rest.end());

  int s = 1;
  int e = l;
  while (s <= e) {
    int mid = (s + e) / 2;
    int c = getRest(rest, l, mid);
    // cout << s << " " << mid << " " << e << " : " << c << "\n";
    if (c > m)
      s = mid + 1;
    else
      e = mid - 1;
  }
  cout << e + 1;
}