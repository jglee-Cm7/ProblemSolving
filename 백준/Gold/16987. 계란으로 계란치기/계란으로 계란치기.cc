#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> egg(10);
vector<bool> isBroken(10);
int mx = 0;

void func(int k) {
  if (k == n) {
    int c = count(isBroken.begin(), isBroken.end(), 1);
    mx = max(c, mx);
    return;
  }

  if (isBroken[k]) {
    func(k + 1);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (k == i) continue;
    if (isBroken[i]) continue;

    egg[k].first -= egg[i].second;
    egg[i].first -= egg[k].second;
    if (egg[k].first <= 0) isBroken[k] = 1;
    if (egg[i].first <= 0) isBroken[i] = 1;
    func(k + 1);
    if (egg[k].first <= 0) isBroken[k] = 0;
    if (egg[i].first <= 0) isBroken[i] = 0;
    egg[k].first += egg[i].second;
    egg[i].first += egg[k].second;
  }

  int c = count(isBroken.begin(), isBroken.end(), 1);
  mx = max(c, mx);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int d, w;
    cin >> d >> w;
    egg[i] = {d, w};
  }

  func(0);
  cout << mx;
}