#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n, 0);
  vector<int> prev(n, -1);
  vector<int> lis;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++) {
    int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
    if (idx == (int)lis.size())
      lis.push_back(arr[i]);
    else
      lis[idx] = arr[i];
    prev[i] = idx;
  }

  cout << lis.size() << "\n";
  int idx = lis.size() - 1;
  for (int i = (int)prev.size() - 1; i >= 0; i--) {
    if (prev[i] == idx) {
      lis[idx] = arr[i];
      idx--;
    }
  }
  for (int l : lis)
    cout << l << " ";
}