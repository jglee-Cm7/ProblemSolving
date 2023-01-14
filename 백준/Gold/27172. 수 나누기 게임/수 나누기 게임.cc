#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n);
  vector<bool> check(1'000'001, false);
  vector<int> score(1'000'001, 0);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr[i] = v;
    check[v] = true;
  }

  for (int v : arr) {
    int cur = v * 2;
    while (cur < 1'000'001) {
      if (check[cur]) {
        score[v]++;
        score[cur]--;
      }
      cur += v;
    }
  }

  for (int v : arr) {
    cout << score[v] << " ";
  }
}