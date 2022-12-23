#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> prev(n + 1);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    prev[v] = prev[v - 1] + 1;
  }

  int mx = *max_element(prev.begin(), prev.end());

  cout << n - mx;
}