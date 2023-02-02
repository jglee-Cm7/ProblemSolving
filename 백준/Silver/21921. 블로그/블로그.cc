#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  vector<int> sl;
  int s = 0;
  for (int i = 0; i < x; i++)
    s += arr[i];
  sl.push_back(s);
  for (int i = x; i < n; i++) {
    s -= arr[i - x];
    s += arr[i];
    sl.push_back(s);
  }

  int mx = *max_element(sl.begin(), sl.end());
  int cnt = count(sl.begin(), sl.end(), mx);
  if (mx == 0)
    cout << "SAD";
  else
    cout << mx << "\n" << cnt;
}