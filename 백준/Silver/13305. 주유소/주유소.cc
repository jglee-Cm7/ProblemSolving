#include <bits/stdc++.h>
using namespace std;
int ac[100005];
int gas[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> gp;
  vector<int> way;
  for (int i = 1; i < n; i++) {
    int v;
    cin >> v;
    ac[i] = ac[i - 1] + v;
  }
  for (int i = 0; i < n; i++) {
    cin >> gas[i];
    gp.push_back({gas[i], i});
  }
  sort(gp.begin(), gp.end());
  int mx = 0x7fffffff;
  for (int i = 0; i < n; i++) {
    if (gp[i].second < mx) {
      way.push_back(gp[i].second);
      mx = gp[i].second;
    }
  }
  reverse(way.begin(), way.end());
  long long ans = (ac[way[0]] - ac[0]) * gas[0];
  for (int i = 1; i < (int)way.size(); i++) {
    long long v = (ac[way[i]] - ac[way[i - 1]]) * gas[way[i - 1]];
    ans += v;
  }
  ans += (ac[n - 1] - ac[way[way.size() - 1]]) * gas[way.size() - 1];
  cout << ans;
}