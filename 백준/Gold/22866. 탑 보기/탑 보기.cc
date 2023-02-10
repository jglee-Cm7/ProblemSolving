#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<pair<int, int>> ans(n, {0x7fffffff, 0});
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  stack<pair<int, int>> s;
  vector<int> left(n);
  vector<int> right(n);
  for (int i = 0; i < n; i++) {
    while (!s.empty() && s.top().first <= arr[i])
      s.pop();
    left[i] = s.size();
    if (!s.empty()) ans[i] = {i + 1 - s.top().second, s.top().second};
    s.push({arr[i], i + 1});
  }
  while (!s.empty())
    s.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && s.top().first <= arr[i])
      s.pop();
    right[i] = s.size();
    if (!s.empty() && (ans[i].first > (s.top().second - (i + 1))))
      ans[i] = {s.top().second - (i + 1), s.top().second};
    s.push({arr[i], i + 1});
  }

  for (int i = 0; i < n; i++) {
    cout << left[i] + right[i] << " ";
    if (ans[i].second != 0) cout << ans[i].second;
    cout << "\n";
  }
}