#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> arr(10);
vector<vector<int>> ans;
void func(int k) {
  if (k == m) {
    ans.push_back(arr);
    return;
  }

  for (int i = 1; i <= n; i++) {
    arr[k] = i;
    func(k + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  func(0);

  for (auto a : ans) {
    for (int i = 0; i < m; i++)
      cout << a[i] << " ";
    cout << "\n";
  }
}