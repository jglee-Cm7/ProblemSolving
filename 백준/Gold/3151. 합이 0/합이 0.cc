#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> std;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    std.push_back(a);
  }

  sort(std.begin(), std.end());

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int s1 = std[i];
    if (s1 > 0) break;
    for (int j = i + 1; j < n; j++) {
      int s2 = std[j];
      long long count =
          upper_bound(std.begin() + j + 1, std.end(), -(s1 + s2)) -
          lower_bound(std.begin() + j + 1, std.end(), -(s1 + s2));
      ans += count;
    }
  }
  cout << ans;
}