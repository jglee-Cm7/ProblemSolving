#include <bits/stdc++.h>
using namespace std;
vector<int> fibo;
void init() {
  fibo.push_back(0);
  fibo.push_back(1);
  for (int i = 2; i < 45; i++)
    fibo.push_back(fibo[i - 1] + fibo[i - 2]);
}

vector<int> solution(int x) {
  vector<int> ans;
  while (x) {
    int i = lower_bound(fibo.begin(), fibo.end(), x) - fibo.begin();
    if (fibo[i] != x) i -= 1;
    ans.push_back(fibo[i]);
    x -= fibo[i];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    vector<int> ans = solution(x);
    for (int i = ans.size() - 1; i >= 0; i--)
      cout << ans[i] << " ";
    cout << "\n";
  }
}