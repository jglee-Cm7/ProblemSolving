#include <bits/stdc++.h>
using namespace std;
long long mn[105];
string mx[105];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  mx[2] = "1", mx[3] = "7";
  mn[2] = 1, mn[3] = 7, mn[4] = 4, mn[5] = 2, mn[6] = 6, mn[7] = 8, mn[8] = 10,
  mn[9] = 18, mn[10] = 22;
  for (int i = 4; i < 101; i++)
    mx[i] = mx[i - 2] + "1";
  for (int i = 11; i < 101; i++) {
    mn[i] = min(mn[i - 7] * 10 + 8, mn[i - 6] * 10);
  }
  while (n--) {
    int v;
    cin >> v;
    cout << mn[v] << " " << mx[v] << "\n";
  }
}