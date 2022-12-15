#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int month[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  int n;
  cin >> n;
  vector<pair<int, int>> flower(n);
  for (int i = 0; i < n; i++) {
    int stm, std, enm, end;
    cin >> stm >> std >> enm >> end;
    flower[i] = {month[stm] + std, month[enm] + end};
  }

  sort(flower.begin(), flower.end(), cmp);
  int cnt = 0;
  int en = 60;
  int i = 0;
  while (1) {
    priority_queue<pair<int, int>> pq;
    for (int j = i; j < n; j++) {
      if (flower[j].second <= en) continue;
      if (flower[j].first <= en) pq.push({flower[j].second, j});
    }
    if (pq.empty()) {
      break;
    }
    auto [fen, fi] = pq.top();
    en = fen;
    i = fi;
    cnt++;
    if (en > 334) break;
  }
  if (cnt == 0 || en <= 334) {
    cout << "0";
    return 0;
  }
  cout << cnt;
}