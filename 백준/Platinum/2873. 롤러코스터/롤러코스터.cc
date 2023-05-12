#include <bits/stdc++.h>
using namespace std;
int board[1010][1010];
int main() {
ios:
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int x = 0, y = 0;
  int mn = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (i % 2 == j % 2) continue;
      if (board[i][j] < mn) {
        mn = board[i][j];
        x = i, y = j;
      }
    }
  }
  string d(n - 1, 'D');
  string u(n - 1, 'U');
  string r(m - 1, 'R');
  string l(m - 1, 'L');
  string ans = "";
  // 열이 홀수 일 때
  if (m % 2) {
    for (int i = 0; i < m; i++) {
      if (i % 2)
        ans += u;
      else
        ans += d;
      ans += "R";
    }
    ans.pop_back();
  } else if (n % 2 && m % 2 == 0) { // 열이 짝수 이고 행이 홀수 일 때
    for (int i = 0; i < n; i++) {
      if (i % 2)
        ans += l;
      else
        ans += r;
      ans += "D";
    }
    ans.pop_back();
  } else { // 행, 열 모두 짝수일 때
    // 위에서 아래로 2줄씩 이동
    for (int i = 0; i < x / 2; i++)
      ans += r + "D" + l + "D";
    // 왼쪽에서 오른쪽으로 2줄씩 이동
    for (int i = 0; i < y / 2; i++)
      ans += "DRUR";
    // 최소지점이 아래쪽에 있을 때
    if (x % 2 == 0 && y % 2) {
      ans += "DR";
      x++;
    }
    // 최소지점이 오른쪽에 있을 때
    else {
      ans += "RD";
      y++;
    }

    for (int i = y; i < m - 1; i += 2)
      ans += "RURD";

    for (int i = x; i < n - 1; i += 2)
      ans += "D" + l + "D" + r;
  }

  cout << ans;
}