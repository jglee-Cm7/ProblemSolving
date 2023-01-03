#include <bits/stdc++.h>
using namespace std;
long long getWoodLength(vector<int> &tree, int h) {
  long long length = 0;
  for (int t : tree) {
    if (t < h) continue;
    length += (long long)(t - h);
  }
  return length;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> tree(n);
  for (int i = 0; i < n; i++)
    cin >> tree[i];

  int st = 1;
  int en = 2e9;
  while (st <= en) {
    int mid = (st + en) / 2;
    long long length = getWoodLength(tree, mid);
    if (length >= m)
      st = mid + 1;
    else
      en = mid - 1;
  }
  cout << en;
}