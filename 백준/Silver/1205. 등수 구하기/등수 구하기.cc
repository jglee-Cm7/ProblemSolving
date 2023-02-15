#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t, p;
  cin >> n >> t >> p;
  vector<int> score;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    score.push_back(v);
  }
  if (n < p) {
    for (int i = 0; i < n; i++) {
      if (score[i] <= t) {
        cout << i + 1;
        return 0;
      }
    }
    cout << n + 1;
  } else {
    if (t <= score[p - 1]) {
      cout << "-1";
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (score[i] <= t) {
        cout << i + 1;
        return 0;
      }
    }
  }
}