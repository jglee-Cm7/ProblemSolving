#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> start(3);
  cin >> start[0] >> start[1] >> start[2];
  vector<vector<int>> mndp(2, vector<int>(3, 0x7fffffff));
  vector<vector<int>> mxdp(2, vector<int>(3, 0));

  for (int i = 0; i < 3; i++) {
    mndp[0][i] = start[i];
    mxdp[0][i] = start[i];
  }

  int dx[3] = {-1, 0, 1};

  for (int i = 1; i < n; i++) {
    vector<int> nxt(3);
    cin >> nxt[0] >> nxt[1] >> nxt[2];

    for (int j = 0; j < 3; j++) {
      mndp[1][j] = 0x7fffffff;
      mxdp[1][j] = 0;
      for (int dir = 0; dir < 3; dir++) {
        int x = j + dx[dir];
        if (x < 0 || x >= 3) continue;
        mndp[1][j] = min(mndp[1][j], mndp[0][x] + nxt[j]);
        mxdp[1][j] = max(mxdp[1][j], mxdp[0][x] + nxt[j]);
      }
    }
    for (int j = 0; j < 3; j++) {
      mndp[0][j] = mndp[1][j];
      mxdp[0][j] = mxdp[1][j];
    }
  }

  int mn = *min_element(mndp[0].begin(), mndp[0].end());
  int mx = *max_element(mxdp[0].begin(), mxdp[0].end());

  cout << mx << " " << mn;
}