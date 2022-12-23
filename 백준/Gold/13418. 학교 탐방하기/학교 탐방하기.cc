#include <bits/stdc++.h>
using namespace std;

// prim
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < m + 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, !c});
    adj[b].push_back({a, !c});
  }

  int mnUphill = 0;
  int mxUphill = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      mnPq;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> mxPq;
  for (int i = 0; i < 2; i++) {
    vector<bool> check(n + 1);
    check[0] = true;
    for (auto [nxt, c] : adj[0]) {
      if (i)
        mxPq.push({c, 0, nxt});
      else
        mnPq.push({c, 0, nxt});
    }

    int cnt = 0;
    int uphill = 0;
    while (cnt < n) {
      int c, a, b;
      if (i)
        tie(c, a, b) = mxPq.top();
      else
        tie(c, a, b) = mnPq.top();
      if (i)
        mxPq.pop();
      else
        mnPq.pop();
      if (check[b]) continue;
      check[b] = true;
      cnt++;
      uphill += c;
      for (auto [nxt, c] : adj[b]) {
        if (!check[nxt]) {
          if (i)
            mxPq.push({c, b, nxt});
          else
            mnPq.push({c, b, nxt});
        }
      }
    }
    if (i)
      mxUphill = uphill;
    else
      mnUphill = uphill;
  }

  cout << (mxUphill * mxUphill) - (mnUphill * mnUphill);
}