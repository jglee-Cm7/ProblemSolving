#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  char g;
  cin >> n >> g;
  set<string> s;
  for (int i = 0; i < n; i++) {
    string u;
    cin >> u;
    s.insert(u);
  }
  if (g == 'Y') cout << s.size();
  else if (g == 'F') cout << s.size() / 2;
  else cout << s.size() / 3;
}