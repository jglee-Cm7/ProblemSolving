#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> arr;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    arr.push_back(s);
  }
  int mx = 0;
  string a, b;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cnt = 0;
      int k = min(arr[i].length(), arr[j].length());
      for (k = 0; k < (int)arr[i].length(); k++) {
        if (arr[i][k] != arr[j][k]) break;
        cnt++;
      }
      if (cnt > mx) {
        mx = cnt;
        a = arr[i];
        b = arr[j];
      }
    }
  }

  cout << a << "\n" << b;
}