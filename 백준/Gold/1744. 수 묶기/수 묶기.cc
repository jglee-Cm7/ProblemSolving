#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr1;
  vector<int> arr2;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v > 0)
      arr1.push_back(v);
    else
      arr2.push_back(v);
  }

  sort(arr1.begin(), arr1.end(), greater<>());
  sort(arr2.begin(), arr2.end());
  int ans = 0;
  for (int i = 0; i < arr1.size(); i++) {
    if (i + 1 < arr1.size()) {
      if (arr1[i] * arr1[i + 1] > arr1[i] + arr1[i + 1]) {
        ans += arr1[i] * arr1[i + 1];
        i++;
      } else {
        ans += arr1[i];
      }
    } else {
      ans += arr1[i];
    }
  }
  for (int i = 0; i < arr2.size(); i++) {
    if (i + 1 < arr2.size()) {
      ans += arr2[i] * arr2[i + 1];
      i++;
    } else {
      ans += arr2[i];
    }
  }
  cout << ans;
}