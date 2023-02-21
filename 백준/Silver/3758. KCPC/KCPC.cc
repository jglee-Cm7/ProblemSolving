#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<vector<int>> p(105, vector<int>(105, 0));
    vector<tuple<int, int, int, int>> score(105, {0, 0, 10101, 10101}); // 팀 번호, 최종점수, 풀이제출 횟수, 마지막 제출시간

    int n, k, id, m;
    cin >> n >> k >> id >> m;
    for (int i = 1; i <= m; i++) {
      int iid, j, s;
      cin >> iid >> j >> s;
      p[iid][j] = max(p[iid][j], s);
      auto &[_, __, sc, st] = score[iid];
      if (sc == 10101)
        sc = 1;
      else
        sc++;
      st = i;
    }

    for (int i = 1; i <= n; i++) {
      int sum = 0;
      for (int j = 1; j <= k; j++)
        sum += p[i][j];
      auto &[tn, s, _, __] = score[i];
      tn = i;
      s = sum;
    }

    sort(score.begin(), score.end(), [](const auto &a, const auto &b) -> bool {
      auto [t1, s1, sc1, st1] = a;
      auto [t2, s2, sc2, st2] = b;
      if (s1 != s2) return s1 > s2;
      if (sc1 != sc2) return sc1 < sc2;
      if (st1 != st2) return st1 < st2;
      return t1 < t2;
    });

    for (int i = 0; i < n; i++) {
      auto [tn, s, sc, st] = score[i];
      if (tn == id) {
        cout << i + 1 << "\n";
        break;
      }
    }
  }
}