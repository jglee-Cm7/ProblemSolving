#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr(10);
vector<int> ans(10);
vector<bool> isUsed(10);
set<vector<int>> s;

void func(int k) {
  if (k == m) {
    s.insert(ans);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!isUsed[i]) {
      ans[k] = arr[i];
      isUsed[i] = 1;
      func(k + 1);
      isUsed[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.begin() + n);
  func(0);
  for (auto ans : s) {
    for (int i = 0; i < m; i++)
      cout << ans[i] << " ";
    cout << "\n";
  }
}