#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n);
  vector<char> ans;
  stack<int> s;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int k = 1;
  for (int i = 0; i < n; i++) {
    while (k <= arr[i]) {
      s.push(k++);
      ans.push_back('+');
    }
    if (!s.empty()) {
      if (s.top() == arr[i]) {
        ans.push_back('-');
        s.pop();
      } else if (s.top() > arr[i]) {
        cout << "NO";
        return 0;
      }
    } else {
      cout << "NO";
      return 0;
    }
  }

  for (char a : ans)
    cout << a << "\n";
}