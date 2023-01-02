#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> elm(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ll v = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      v *= 10;
      v += s[i] - '0';
    }
    elm[i] = v;
  }
  sort(elm.begin(), elm.end());
  for (auto e : elm)
    cout << e << "\n";
}