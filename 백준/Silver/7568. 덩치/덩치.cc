#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back({x, y});
  }

  for (int i = 0; i < n; i++) {
    int rank = 1;
    auto [x, y] = arr[i];
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      auto [nx, ny] = arr[j];
      if (nx > x && ny > y) rank++;
    }
    cout << rank << " ";
  }
}