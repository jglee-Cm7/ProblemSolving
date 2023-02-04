#include <bits/stdc++.h>
using namespace std;

int n, k, p, x;
int rs[10][10];
int num[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010,
               0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};

bool reverse(int a, int b) {
  int sum = 0;
  for (int j = 0; j < k; j++) {
    sum += rs[a % 10][b % 10];
    if (a > 0) a /= 10;
    if (b > 0) b /= 10;
    if (sum > p) return 0;
  }
  if (sum > 0)
    return 1;
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> p >> x;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      rs[i][j] = __builtin_popcount(num[i] ^ num[j]);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    if (reverse(i, x)) {
      ans++;
    }
  }

  cout << ans;
}