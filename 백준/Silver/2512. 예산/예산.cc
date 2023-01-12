#include <bits/stdc++.h>
using namespace std;

int getBudget(vector<int> &p, int m) {
  int sum = 0;
  for (int r : p)
    sum += r < m ? r : m;
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  cin >> m;

  int s = 1;
  int e = 1e9;
  while (s <= e) {
    int mid = (s + e) / 2;
    int b = getBudget(p, mid);
    if (b > m)
      e = mid - 1;
    else
      s = mid + 1;
  }
  cout << (e == 1e9 ? *max_element(p.begin(), p.end()) : e);
}