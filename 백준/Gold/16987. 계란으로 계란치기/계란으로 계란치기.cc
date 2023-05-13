#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> eggs(10);
vector<bool> isBroken(10, 0);
int mx;
void func(int k) {
  if (k == n) {
    int broken = count(isBroken.begin(), isBroken.end(), 1);
    mx = max(mx, broken);
    return;
  }

  if (isBroken[k]) {
    func(k + 1);
    return;
  }

  auto &[s, w] = eggs[k];
  for (int i = 0; i < n; i++) {
    if (k == i) continue;
    if (isBroken[i]) continue;
    auto &[ns, nw] = eggs[i];

    s -= nw;
    ns -= w;
    if (s <= 0) isBroken[k] = 1;
    if (ns <= 0) isBroken[i] = 1;
    func(k + 1);
    if (s <= 0) isBroken[k] = 0;
    if (ns <= 0) isBroken[i] = 0;
    s += nw;
    ns += w;
  }

  if (k == n - 1) {
    func(k + 1);
    return;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int s, w;
    cin >> s >> w;
    eggs[i] = {s, w};
  }

  func(0);

  cout << mx;
}