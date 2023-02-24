#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int vis[N][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n == k) {
    cout << "0";
    return 0;
  }
  for (int i = 0; i < 2; i++)
    fill(vis[i], vis[i] + N, -1);

  queue<pair<int, int>> q;
  q.push({n, 0});
  while (!q.empty()) {
    auto [cur, t] = q.front();
    q.pop();
    int nx[3] = {cur - 1, cur + 1, cur * 2};
    for (int dir = 0; dir < 3; dir++) {
      int nxt = nx[dir];
      if (nxt < 0 || nxt >= N) continue;
      if (vis[nxt][(t + 1) % 2] != -1) continue;
      vis[nxt][(t + 1) % 2] = t + 1;
      q.push({nxt, t + 1});
    }
  }
  int t = 1;
  k += t;
  while (k <= 500000) {
    if (vis[k][t % 2] <= t) {
      cout << t;
      return 0;
    }
    t++;
    k += t;
  }

  cout << "-1";
}