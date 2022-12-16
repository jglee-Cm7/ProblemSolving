#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  priority_queue<long long, vector<long long>, greater<>> pq;
  for (int i = 0; i < n; i++) {
    long long v;
    cin >> v;
    pq.push(v);
  }

  while (m--) {
    long long a = pq.top();
    pq.pop();
    long long b = pq.top();
    pq.pop();
    pq.push(a + b);
    pq.push(a + b);
  }
  long long ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
}