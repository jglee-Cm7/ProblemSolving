#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr(10);
vector<vector<int>> ans;
int isUsed[10];

void bt(int k) {
  if (k == m) {
    ans.push_back(arr);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!isUsed[i]) {
      arr[k] = i;
      isUsed[i] = 1;
      bt(k + 1);
      isUsed[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  bt(0);

  for (auto a : ans) {
    for (int i = 0; i < m; i++)
      cout << a[i] << " ";
    cout << "\n";
  }
}