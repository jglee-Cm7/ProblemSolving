#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> sAdj[105];
  vector<int> bAdj[105];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    sAdj[a].push_back(b);
    bAdj[b].push_back(a);
  }
  int ans = n == 1 ? 1 : 0;
  int ts = ((n + 1) / 2) - 1;
  for (int i = 1; i <= n; i++) {
    deque<int> q1;
    deque<int> q2;
    vector<int> sVis(105);
    vector<int> bVis(105);
    int sCnt = 0;
    int bCnt = 0;
    q1.push_back(i);
    sVis[i] = 1;
    q2.push_back(i);
    bVis[i] = 1;
    while (!q1.empty()) {
      int cur = q1.front();
      q1.pop_front();
      for (int nxt : sAdj[cur]) {
        if (sVis[nxt]) continue;
        q1.push_back(nxt);
        sVis[nxt] = 1;
        sCnt++;
      }
      if (sCnt > ts) break;
    }
    while (!q2.empty()) {
      int cur = q2.front();
      q2.pop_front();
      for (int nxt : bAdj[cur]) {
        if (bVis[nxt]) continue;
        q2.push_back(nxt);
        bVis[nxt] = 1;
        bCnt++;
      }
      if (bCnt > ts) break;
    }
    if (sCnt > ts) ans++;
    if (bCnt > ts) ans++;
  }

  cout << ans;
}