#include <bits/stdc++.h>
using namespace std;

int board[20][20];
int isUsed[3][40]; // [0]: y축(열) , [1]: ↙ , [2]: ↘ 중복 체크
int ans = 0;
// n: 전체 행 길이, k: 현재 행
void queen(int n, int k) {
  if (k == n) {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!isUsed[0][i] && !isUsed[1][k + i] && !isUsed[2][k - i + n - 1]) {
      board[k][i] = 1;
      isUsed[0][i] = 1;
      isUsed[1][k + i] = 1;
      isUsed[2][k - i + n - 1] = 1;
      queen(n, k + 1);
      board[k][i] = 0;
      isUsed[0][i] = 0;
      isUsed[1][k + i] = 0;
      isUsed[2][k - i + n - 1] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  queen(n, 0);

  cout << ans;
}