#include <bits/stdc++.h>
using namespace std;
int n;
int f[10010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> f[i];

  int answer = 0;

  for (int i = 0; i < n; i++) {
    if (f[i] == 0) continue;
    if (f[i + 1] == 0) {
      answer += f[i] * 3;
      f[i] = 0;
      continue;
    } else {

      if (f[i + 1] > f[i + 2]) {
        int mn = min(f[i + 1] - f[i + 2], f[i]);
        answer += mn * 5;
        f[i] -= mn, f[i + 1] -= mn;
        if (f[i] != 0) {
          mn = min(f[i], f[i + 2]);
          answer += mn * 7;
          f[i] -= mn, f[i + 1] -= mn, f[i + 2] -= mn;
        }
        if (f[i] != 0) {
          answer += f[i] * 3;
          f[i] = 0;
        }
      } else {
        int mn = min(min(f[i], f[i + 1]), f[i + 2]);
        answer += mn * 7;
        f[i] -= mn, f[i + 1] -= mn, f[i + 2] -= mn;
        if (f[i] != 0) {
          answer += f[i] * 3;
          f[i] = 0;
        }
      }
    }
  }

  cout << answer;
}