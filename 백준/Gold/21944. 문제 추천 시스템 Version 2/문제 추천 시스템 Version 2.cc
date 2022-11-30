#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; // 문제 개수
  cin >> n;

  multiset<pair<int, int>> gs[105];
  multiset<pair<int, int>> s;
  decltype(s)::iterator sIdx[100005];
  decltype(s)::iterator gsIdx[100005];
  int pg[100005];

  for (int i = 0; i < n; i++) {
    int p, l, g; // 문제 번호 / 난이도 / 문제 분류
    cin >> p >> l >> g;
    sIdx[p] = s.insert({l, p});
    gsIdx[p] = gs[g].insert({l, p});
    pg[p] = g;
  }

  int m; // 명령문 개수
  cin >> m;

  while (m--) {
    string op;
    int x, y, z;
    cin >> op >> x;
    if (op == "recommend") {
      cin >> y;
      cout << (y > 0 ? (--gs[x].end()) : gs[x].begin())->second << '\n';
    } else if (op == "recommend2") {
      cout << (x > 0 ? (--s.end()) : s.begin())->second << '\n';
    } else if (op == "recommend3") {
      cin >> y;
      auto it = s.lower_bound({y, 0});
      if (x == 1) {
        if (it == s.end())
          cout << "-1\n";
        else
          cout << it->second << "\n";
      } else {
        if (it == s.begin())
          cout << "-1\n";
        else
          cout << (--it)->second << "\n";
      }
    } else if (op == "add") {
      cin >> y >> z;
      sIdx[x] = s.insert({y, x});
      gsIdx[x] = gs[z].insert({y, x});
      pg[x] = z;
    } else { // solved
      s.erase(sIdx[x]);
      gs[pg[x]].erase(gsIdx[x]);
    }
  }
}