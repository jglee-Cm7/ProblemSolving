#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> range(MAXN + 1);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    while (a < b)
      range[++a]++;
  }

  int j = 0;
  int sum = 0;
  for (int i = 0; i < MAXN + 1; i++) {
    sum -= range[i];
    while (j < MAXN && sum < k) {
      sum += range[++j];
    }
    if (sum == k) {
      cout << i << " " << j;
      return 0;
    }
    if (j == MAXN && sum < k) break;
  }

  cout << "0 0";
}