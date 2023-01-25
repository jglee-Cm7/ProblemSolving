#include <bits/stdc++.h>
using namespace std;
int r, c;
vector<vector<int>> board(25, vector<int>(25));
vector<bool> isUsed(30);
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;

void func(int i, int j, int k) {
  ans = max(ans, k);

  for (int dir = 0; dir < 4; dir++) {
    int x = i + dx[dir];
    int y = j + dy[dir];
    if (x < 0 || x >= r || y < 0 || y >= c) continue;
    int c = board[x][y];
    if (isUsed[c] == 1) continue;
    isUsed[c] = 1;
    func(x, y, k + 1);
    isUsed[c] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char c;
      cin >> c;
      board[i][j] = c - 'A';
    }
  }

  int c = board[0][0];
  isUsed[c] = 1;
  func(0, 0, 1);

  cout << ans;
}