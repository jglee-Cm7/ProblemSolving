#include <bits/stdc++.h>
using namespace std;
int n;
char board[7][7];
vector<pair<int, int>> tc;
bool func(int k, int x) {
  if (k == 3) {
    bool no = 0;
    for (auto [a, b] : tc) {
      for (int i = a; i < n; i++) {
        if (board[i][b] == 'S') {
          no = 1;
          break;
        }
        if (board[i][b] == 'O') break;
      }
      if (no) break;
      for (int i = a; i >= 0; i--) {
        if (board[i][b] == 'S') {
          no = 1;
          break;
        }
        if (board[i][b] == 'O') break;
      }
      if (no) break;
      for (int i = b; i < n; i++) {
        if (board[a][i] == 'S') {
          no = 1;
          break;
        }
        if (board[a][i] == 'O') break;
      }
      if (no) break;
      for (int i = b; i >= 0; i--) {
        if (board[a][i] == 'S') {
          no = 1;
          break;
        }
        if (board[a][i] == 'O') break;
      }
      if (no) break;
    }

    if (no)
      return 0;
    else
      return 1;
  }

  for (; x < n * n; x++) {
    int i = x / n;
    int j = x % n;
    if (board[i][j] != 'X') continue;
    board[i][j] = 'O';
    if (func(k + 1, x)) return 1;
    board[i][j] = 'X';
  }

  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'T') tc.push_back({i, j});
    }
  }

  if (func(0, 0))
    cout << "YES";
  else
    cout << "NO";
}