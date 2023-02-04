#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> title(n);
  vector<int> limit(n);
  for (int i = 0; i < n; i++) {
    cin >> title[i] >> limit[i];
  }
  while (m--) {
    int v;
    cin >> v;
    int idx = lower_bound(limit.begin(), limit.end(), v) - limit.begin();
    cout << title[idx] << "\n";
  }
}