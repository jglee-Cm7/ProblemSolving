#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int h, k;
    cin >> h >> k;
    arr.push_back({h, k});
  }
  sort(arr.begin(), arr.end(), greater<>());

  multiset<int> g;
  for (auto [h, k] : arr) {
    auto it = g.lower_bound(k);
    if (it == g.begin()) { // g가 비어있을 경우 g.end() == g.begin 이라서 여기서
                           // 걸림 , g가 비어있지 않더라도 k가 1이면 새 그룹을
                           // 형성해줘야하는데 g의 begin에 걸릴 것.
      g.insert(1);
    } else {
      int size = *prev(it);
      g.erase(prev(it));
      g.insert(size + 1);
    }
  }
  cout << g.size();
}