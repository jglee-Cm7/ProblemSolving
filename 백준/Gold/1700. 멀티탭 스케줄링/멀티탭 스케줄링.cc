#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> order(k);
  vector<bool> app(k + 1);
  vector<int> plug;

  if (n >= k) {
    cout << "0";
    return 0;
  }
  for (int &p : order)
    cin >> p;

  int ans = 0;
  for (int i = 0; i < k; i++) {
    int p = order[i];
    if (app[p]) continue;       // 앱이 사용 상태이면 다음으로
    if ((int)plug.size() < n) { // 플러그에 여유공간이 남아있으면
      plug.push_back(p);        // 플러그에 꽂고
      app[p] = true;            // 앱을 사용상태로 전환.
    } else {
      // plug에 꽂힌 기기들 중 가장 늦게 사용할 기기를 뽑는다.
      vector<int> prePlug(n, 105);
      int target = 0;
      for (int j = i; j < k; j++) {
        for (int x = 0; x < n; x++) {
          if (prePlug[x] == 105 && plug[x] == order[j]) {
            prePlug[x] = j;
            break;
          }
        }
      }
      for (int j = 0; j < n; j++) {
        if (prePlug[target] < prePlug[j]) target = j;
      }
      app[plug[target]] = false;
      plug[target] = p;
      app[p] = true;
      ans++;
    }
  }

  cout << ans;
}