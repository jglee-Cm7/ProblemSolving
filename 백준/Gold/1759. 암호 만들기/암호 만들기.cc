#include <bits/stdc++.h>
using namespace std;

int l, c;
int arr[15];
char chr[15];

void func(int k, int v, int cs) {
  if (k == l && v > 0 && cs > 1) {
    for (int i = 0; i < l; i++)
      cout << chr[arr[i]];
    cout << "\n";
    return;
  }

  int s = k != 0 ? arr[k - 1] + 1 : 0;
  for (int i = s; i < c; i++) {
    arr[k] = i;
    if (chr[i] == 'a' || chr[i] == 'e' || chr[i] == 'i' || chr[i] == 'o' ||
        chr[i] == 'u')
      func(k + 1, v + 1, cs);
    else
      func(k + 1, v, cs + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> c;
  for (int i = 0; i < c; i++)
    cin >> chr[i];

  sort(chr, chr + c);

  func(0, 0, 0);
}