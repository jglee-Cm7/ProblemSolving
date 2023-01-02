#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  cin >> n >> c;
  map<int, pair<int, int>> freq;
  vector<tuple<int, int, int>> freqArr;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    int f, idx;
    tie(f, idx) = freq[v];
    f++;
    if (idx == 0) idx = i;
    freq[v] = {f, idx};
  }
  for (auto [key, value] : freq)
    freqArr.push_back({value.first, value.second, key});
  sort(freqArr.begin(), freqArr.end(),
       [](const auto &a, const auto &b) -> bool {
         int f1, f2, idx1, idx2, v1, v2;
         tie(f1, idx1, v1) = a;
         tie(f2, idx2, v2) = b;
         if (f1 == f2) return idx1 < idx2;
         return f1 > f2;
       });
  for (auto [f, idx, value] : freqArr) {
    while (f--)
      cout << value << " ";
  }
}