#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<int> mxq;
  priority_queue<int, vector<int>, greater<int>> mnq;

  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    mxq.push(v);
    if (mnq.size() < mxq.size() - 1) {
      mnq.push(mxq.top());
      mxq.pop();
    }
    if (!mnq.empty() && mxq.top() > mnq.top()) {
      mnq.push(mxq.top());
      mxq.push(mnq.top());
      mxq.pop();
      mnq.pop();
    }

    cout << mxq.top() << "\n";
  }
}