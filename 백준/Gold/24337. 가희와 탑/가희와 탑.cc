#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> ans;
  for (int i = 1; i < a; i++)
    ans.push_back(i);
  ans.push_back(max(a, b));
  for (int i = b - 1; i > 0; i--)
    ans.push_back(i);

  if ((int)ans.size() > n) {
    cout << "-1";
    return 0;
  }
  cout << ans[0] << " ";
  for (int i = 0; i < n - (int)ans.size(); i++)
    cout << "1 ";
  for (int i = 1; i < (int)ans.size(); i++)
    cout << ans[i] << " ";
}