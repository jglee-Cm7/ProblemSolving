#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int num[10];
bool isUsed[10];
void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << num[arr[i]] << " ";
    cout << "\n";
    return;
  }

  int s = k != 0 ? arr[k - 1] + 1 : 0;
  int tmp = 0;
  for (int i = s; i < n; i++) {
    if (!isUsed[i] && tmp != num[i]) {
      isUsed[i] = 1;
      arr[k] = i;
      tmp = num[i];
      func(k + 1);
      isUsed[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> num[i];

  sort(num, num + n);
  func(0);
}