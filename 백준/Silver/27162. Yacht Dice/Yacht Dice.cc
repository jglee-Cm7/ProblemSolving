#include <bits/stdc++.h>
using namespace std;
int yacht(vector<int> &arr, int type) {
  int result = 0;
  map<int, int> dice;
  for (int a : arr)
    dice[a]++;

  switch (type) {
  case 0:
    result = dice[1] + 2;
    break;
  case 1:
    result = (dice[2] + 2) * 2;
    break;
  case 2:
    result = (dice[3] + 2) * 3;
    break;
  case 3:
    result = (dice[4] + 2) * 4;
    break;
  case 4:
    result = (dice[5] + 2) * 5;
    break;
  case 5:
    result = (dice[6] + 2) * 6;
    break;
  case 6:
    for (auto [key, value] : dice) {
      if (value >= 2) result = key * 4;
    }
    break;
  case 7:
    if (dice.size() == 1) {
      result += arr[0] * 3;
      if (result == 18)
        result += 10;
      else
        result += 12;
    } else if (dice.size() == 2) {
      result += (dice.begin()->first) * 2;
      result += (next(dice.begin())->first) * 3;
    }
    break;
  case 8:
    if (dice.size() == 3 && dice[6] == 0) result = 30;
    break;
  case 9:
    if (dice.size() == 3 && dice[1] == 0) result = 30;
    break;
  case 10:
    if (dice.size() == 1) result = 50;
    break;
  case 11:
    result = accumulate(arr.begin(), arr.end(), 12);
    break;
  default:
    break;
  }

  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string pre;
  vector<int> arr(3);
  cin >> pre;
  for (int &a : arr)
    cin >> a;

  int mx = 0;
  for (int i = 0; i < (int)pre.length(); i++) {
    if (pre[i] == 'Y') mx = max(mx, yacht(arr, i));
  }
  cout << mx;
}