#include <bits/stdc++.h>
using namespace std;

int n;
const int m = 6;
int arr[m];
int num[50];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << num[arr[i]] << " ";
    cout << "\n";
    return;
  }
  int s = k != 0 ? arr[k - 1] + 1 : 0;
  for (int i = s; i < n; i++) {
    arr[k] = i;
    func(k + 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n != 0) {
    for (int i = 0; i < n; i++)
      cin >> num[i];
    sort(num, num + n);
    func(0);
    cout << "\n";
    cin >> n;
  }
}