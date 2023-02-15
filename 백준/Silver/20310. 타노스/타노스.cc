#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int z = count(s.begin(), s.end(), '0');
  for (int i = 0; i < z / 2; i++)
    cout << "0";
  for (int i = 0; i < (s.length() - z) / 2; i++)
    cout << "1";
}