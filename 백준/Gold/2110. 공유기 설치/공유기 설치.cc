#include <bits/stdc++.h>
using namespace std;

int getRouterCount(vector<int> &house, int distance) {
  int count = 1;
  int h = house[0];

  for (int i = 1; i < (int)house.size(); i++) {
    if (house[i] - h >= distance) {
      count++;
      h = house[i];
    }
  }

  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  cin >> n >> c;
  vector<int> house(n);
  for (int i = 0; i < n; i++)
    cin >> house[i];

  sort(house.begin(), house.end());

  int st = 1;
  int en = 1e9;
  while (st <= en) {
    int mid = (st + en) / 2;
    int count = getRouterCount(house, mid);
    if (count < c)
      en = mid - 1;
    else
      st = mid + 1;
  }
  cout << en;
}