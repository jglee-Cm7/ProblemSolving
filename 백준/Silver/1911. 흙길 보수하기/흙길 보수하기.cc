#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, l;
  cin >> n >> l;
  vector<pair<int, int>> pool;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    pool.push_back({a, b});
  }
  sort(pool.begin(), pool.end());

  int answer = 0;
  int pos = pool[0].first;
  for (int i = 0; i < n; i++) {
    auto [a, b] = pool[i];
    if (pos < a) pos = a;
    while (pos < b) {
      pos += l;
      answer++;
    }
  }
  cout << answer;
}