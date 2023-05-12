#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, v;
  cin >> n;
  priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    pq.push({k, i});
    if (i == 0) v = k;
  }

  int ans = 0;
  while (!pq.empty()) {
    auto [k, i] = pq.top();
    pq.pop();
    if (i == 0 && k == v) break;
    if (i == 0) continue;
    v++;
    k--;
    ans++;
    if (k > 0) pq.push({k, i});
    pq.push({v, 0});
  }

  cout << ans;
}