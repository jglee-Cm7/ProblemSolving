#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> goal;
int solve(vector<bool> arr) {
  int result = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] == goal[i - 1]) continue;
    result++;
    arr[i - 1] = !arr[i - 1];
    arr[i] = !arr[i];
    if (i == n - 1) continue;
    arr[i + 1] = !arr[i + 1];
  }
  if (arr[n - 1] != goal[n - 1]) result = -1;

  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<bool> arr;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    arr.push_back(a[i] - '0');
    goal.push_back(b[i] - '0');
  }

  int c1 = solve(arr);
  arr[0] = !arr[0];
  arr[1] = !arr[1];
  int c2 = solve(arr);
  if (c2 != -1) c2 += 1;
  int ans = min(c1, c2);
  if (ans != -1)
    cout << ans;
  else
    cout << max(c1, c2);
}