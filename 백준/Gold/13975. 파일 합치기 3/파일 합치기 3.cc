#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    priority_queue<ll, vector<ll>, greater<>> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      pq.push(v);
    }
    ll ans = 0;
    while (pq.size() > 1) {
      ll a = pq.top();
      pq.pop();
      ll b = pq.top();
      pq.pop();
      ans += (ll)(a + b);
      pq.push(a + b);
    }
    cout << ans << "\n";
  }
}