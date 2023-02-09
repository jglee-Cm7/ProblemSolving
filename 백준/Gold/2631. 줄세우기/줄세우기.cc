#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }

  vector<int> lis;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
    if (idx == (int)lis.size())
      lis.push_back(arr[i]);
    else
      lis[idx] = arr[i];
  }
  cout << n - lis.size();
}