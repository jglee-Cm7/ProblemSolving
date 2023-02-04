#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p, m;
  cin >> p >> m;
  vector<pair<int, set<pair<string, int>>>> room;
  for (int i = 0; i < p; i++) {
    int lv;
    string id;
    cin >> lv >> id;
    bool find = 0;
    for (auto &[rlv, team] : room) {
      if (lv >= rlv - 10 && lv <= rlv + 10 && (int)team.size() < m) {
        team.insert({id, lv});
        find = 1;
        break;
      }
    }
    if (!find) {
      set<pair<string, int>> team;
      team.insert({id, lv});
      room.push_back({lv, team});
    }
  }

  for (auto [_, team] : room) {
    if ((int)team.size() == m)
      cout << "Started!\n";
    else
      cout << "Waiting!\n";
    for (auto [id, lv] : team) {
      cout << lv << " " << id << "\n";
    }
  }
}