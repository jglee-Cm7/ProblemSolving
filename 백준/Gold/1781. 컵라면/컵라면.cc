#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<int> pq;
  vector<vector<int>> noodleByDeadline(200'005);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    noodleByDeadline[a].push_back(b);
  }

  int ans = 0;
  for (int i = 200'004; i > 0; i--) {
    for (int noodle : noodleByDeadline[i]) {
      pq.push(noodle);
    }
    if (pq.empty()) continue;
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
}