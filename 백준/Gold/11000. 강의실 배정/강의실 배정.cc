#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> lesson;
  for (int i = 0; i < n; i++) {
    int st, en;
    cin >> st >> en;
    lesson.push_back({st, 1});
    lesson.push_back({en, -1});
  }
  sort(lesson.begin(), lesson.end());

  int ans = 0;
  int cnt = 0;
  int t = lesson[0].first;
  for (int i = 0; i < 2 * n; i++) {
    if (t != lesson[i].first) {
      ans = max(ans, cnt);
      t = lesson[i].first;
    }
    cnt += lesson[i].second;
  }
  cout << ans;
}
