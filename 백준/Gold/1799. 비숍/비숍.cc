#include <bits/stdc++.h>
using namespace std;

int n;
// [0]-> 0 or 1 (흑백) , [1]: ↘ 방향으로 묶음
vector<pair<int, int>> board[2][20];
// [0]: 흑, 백 , [1]: ↙ 방향으로 중복 체크
vector<vector<bool>> isUsed(2, vector<bool>(30));
int ans[2];
void func(int color, int idx, int cnt) {
  if (idx == (2 * n)) {
    ans[color] = max(ans[color], cnt);
    return;
  }

  for (auto [i, j] : board[color][idx]) {
    if (isUsed[color][i + j]) continue;
    isUsed[color][i + j] = 1;
    func(color, idx + 1, cnt + 1);
    isUsed[color][i + j] = 0;
  }
  func(color, idx + 1, cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;
      if (v) board[(i + j + 1) % 2][i - j + n - 1].push_back({i, j});
    }
  }

  func(0, 0, 0);
  func(1, 0, 0);
  cout << ans[0] + ans[1];
}