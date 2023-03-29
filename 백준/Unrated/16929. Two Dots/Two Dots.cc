#include <bits/stdc++.h>
using namespace std;
int n, m;
char board[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool dfs(int sx, int sy) {
  char c = board[sx][sy];
  vector<vector<int>> vis(n, vector<int>(m, 0));
  stack<tuple<int, int, int>> st;
  st.push({sx, sy, 1});

  while (!st.empty()) {
    auto [x, y, k] = st.top();
    st.pop();
    if (vis[x][y]) continue;
    vis[x][y] = k;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] != c) continue;
      if (sx == nx && sy == ny && k >= 3) return true;
      if (vis[nx][ny]) continue;
      st.push({nx, ny, k + 1});
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      board[i][j] = s[j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dfs(i, j)) {
        cout << "Yes";
        return 0;
      }
    }
  }

  cout << "No";
  return 0;
}