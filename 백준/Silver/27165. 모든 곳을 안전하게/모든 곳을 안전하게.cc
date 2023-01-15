#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n;
  vector<int> board(n + 1);
  for (int &b : board)
    cin >> b;
  cin >> x;

  bool safe = false;
  int c = count(board.begin(), board.end(), 1);
  int s = 0;
  if (c == 0) {
    for (int i = 0; i <= n; i++) {
      if (i + x > n) break;
      if (board[i] > 2 && board[i + x] > 1) {
        safe = true;
        s = i;
        break;
      }
    }
  } else if (c == 1) {
    for (int i = 0; i <= n; i++) {
      if (i + x > n) break;
      if ((board[i] > 2 && board[i + x] == 1) ||
          (board[i] == 1 && board[i + x] > 1)) {
        safe = true;
        s = i;
        break;
      }
    }
  } else if (c == 2) {
    for (int i = 0; i <= n; i++) {
      if (i + x > n) break;
      if (board[i] == 1 && board[i + x] == 1) {
        safe = true;
        s = i;
        break;
      }
    }
  }

  if (safe)
    cout << "YES\n" << s << " " << s + x;
  else
    cout << "NO\n";
}