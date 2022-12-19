#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> line;
  vector<pair<int, int>> mLine;
  for (int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    line.push_back({s, e});
  }
  sort(line.begin(), line.end());
  mLine.push_back(line[0]);
  for (int i = 1; i < n; i++) {
    if (mLine[mLine.size() - 1].second < line[i].first) {
      mLine.push_back(line[i]);
      continue;
    }
    if (line[i].first <= mLine[mLine.size() - 1].second)
      mLine[mLine.size() - 1].second =
          max(mLine[mLine.size() - 1].second, line[i].second);
  }

  int ans = 0;
  for (auto [s, e] : mLine) {
    ans += e - s;
  }
  cout << ans;
}