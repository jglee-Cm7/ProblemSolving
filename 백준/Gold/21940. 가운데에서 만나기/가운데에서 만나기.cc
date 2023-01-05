#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> floyd(n + 1, vector<int>(n + 1, 2000));
  while (m--) {
    int a, b, t;
    cin >> a >> b >> t;
    floyd[a][b] = t;
  }
  for (int i = 1; i <= n; i++)
    floyd[i][i] = 0;
  cin >> k;
  vector<int> stp(k);
  for (int i = 0; i < k; i++)
    cin >> stp[i];

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }
  }

  vector<pair<int, int>> rtp;
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    // 각 친구이 도시별(i)로 왕복시간을 체크
    for (int s : stp) {
      int rt = floyd[s][i] + floyd[i][s];
      // 가장 시간이 오래걸리는 친구의 왕복시간 저장.
      mx = max(mx, rt);
    }
    // i 도시로 갈 때 가장 시간이 오래걸리는 친구의 왕복시간
    rtp.push_back({mx, i});
  }

  sort(rtp.begin(), rtp.end());
  for (int i = 0; i < (int)rtp.size(); i++) {
    cout << rtp[i].second << " ";
    if (i + 1 < (int)rtp.size() && rtp[i].first != rtp[i + 1].first) break;
  }
}