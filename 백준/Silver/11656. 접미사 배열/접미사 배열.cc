#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  vector<string> arr;
  for (int i = 0; i < (int)s.size(); i++)
    arr.push_back(s.substr(i));
  sort(arr.begin(), arr.end());
  for (auto v : arr)
    cout << v << "\n";
}