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
    if (pq.empty() && v == 0)
      cout << "0\n";
    else if (!pq.empty() && v == 0) {
      cout << pq.top() << "\n";
      pq.pop();
    } else {
      pq.push(v);
    }
  }
}