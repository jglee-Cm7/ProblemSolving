#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<pair<int, int>> rs;
  map<int, int> pm;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int p, l;
    cin >> p >> l;
    pm.insert({p, l});
    rs.insert({l, p});
  }
  
  int m;
  cin >> m;

  while (m--) {
    int v, p, l;
    string op;
    cin >> op;
    if (op == "add") {
      cin >> p >> l;
      auto it = pm.find(p);
      if (it != pm.end()) {
        rs.erase({it->second, it->first});
        pm.erase(it);
      }
      pm.insert({p, l});
      rs.insert({l, p});
    } else if (op == "recommend") {
      cin >> v;
      if (v == 1) {
        auto it = rs.rbegin();
        cout << it->second << "\n";
      } else {
        auto it = rs.begin();
        cout << it->second << "\n";
      }
    } else if (op == "solved") {
      cin >> p;
      auto it = pm.find(p);
      rs.erase({it->second, it->first});
      pm.erase(it);
    }
  }
}