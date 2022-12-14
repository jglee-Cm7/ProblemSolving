#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    pq.push(v);
  }

  int ans = 0;
  while ((int)pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ans += a + b;
    pq.push(a + b);
  }

  cout << ans;
}