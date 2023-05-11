#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[55][55];
int B[55][55];

bool flip(int x, int y) {
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      if (i >= n || j >= m) return 0;
      A[i][j] = !A[i][j];
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      A[i][j] = s[j] - '0';
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      B[i][j] = s[j] - '0';
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] == B[i][j]) continue;
      if (!flip(i, j)) {
        cout << -1;
        return 0;
      }
      ans++;
    }
  }

  cout << ans;
}