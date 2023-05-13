#include <bits/stdc++.h>
using namespace std;
int n, m;
bool nemo[30][30];
int cnt = 0;
void func(int x, int y) {
  if (x == n) {
    for (int i = 0; i <= n - 2; i++) {
      for (int j = 0; j <= m - 2; j++) {
        if (nemo[i][j] && nemo[i][j + 1] && nemo[i + 1][j] &&
            nemo[i + 1][j + 1])
          return;
      }
    }
    cnt++;
    return;
  }

  int ny = y + 1 == m ? 0 : y + 1;
  int nx = ny == 0 ? x + 1 : x;

  nemo[x][y] = 1;
  func(nx, ny);

  nemo[x][y] = 0;
  func(nx, ny);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  func(0, 0);
  cout << cnt;
}