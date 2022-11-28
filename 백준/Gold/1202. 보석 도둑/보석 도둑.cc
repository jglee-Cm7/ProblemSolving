#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second)
    return a.first > b.first;
  else
    return a.second > b.second;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> gem(n);
  multiset<int> bag;

  for (int i = 0; i < n; i++) {
    int m, v;
    cin >> m >> v;
    gem[i] = {m, v};
  }
  for (int i = 0; i < k; i++) {
    int b;
    cin >> b;
    bag.insert(b);
  }

  sort(gem.begin(), gem.end(), cmp);

  long long ans = 0;
  for (auto g : gem) {
    auto it = bag.lower_bound(g.first);
    if (it != bag.end()) {
      ans += g.second;
      bag.erase(it);
    }
  }

  cout << ans;
}
